ERASE       =   \033[2K\r
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

NAME = ircserv

RM	= rm -rf

CC = c++ -std=c++98

FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp Utils.cpp

SRCS_CMD = Command.cpp

SRCS_CMDS = help.cpp join.cpp kick.cpp nick.cpp notice.cpp part.cpp pass.cpp privmsg.cpp quit.cpp user.cpp who.cpp ping.cpp pong.cpp

HEAD = server.hpp client.hpp

HEAD_COMPO = Channel.hpp

HEAD_CMD = Command.hpp ListCommand.hpp

INCS = $(addprefix ./includes/network/, $(HEAD))

INCS_COMPO = $(addprefix .includes/network/components, $(HEAD_COMPO))

INCS_CMD = $(addprefix ./includes/commands/, $(HEAD_CMD))

OBJS = $(addprefix ./srcs/, $(SRCS:.cpp=.o))

OBJS_CMDS = $(addprefix ./srcs/commands/list/, $(SRCS_CMDS:.cpp=.o))

OBJS_CMD = $(addprefix ./srcs/commands/, $(SRCS_CMD:.cpp=.o))

$(NAME):	$(OBJS) $(OBJS_CMD) $(OBJS_CMDS)
			$(CC) $(FLAGS) $(OBJS) $(OBJS_CMD) $(OBJS_CMDS) -o $(NAME)

all:	$(NAME)

%.o:%.cpp	$(INCS) $(INCS_COMPO) $(INCS_CMD)
			$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) srcs/*.o
		@$(RM) srcs/commands/*.o
		@$(RM) srcs/commands/list/*.o
		@$(RM) *.o
		@printf "$(ERASE)$(RED)-> All files *.o cleaned$(END)\n"

fclean:	clean
		@$(RM) ircserv
		@printf "$(ERASE)$(RED)-> Executable cleaned$(END)\n"

re: all clean fclean re