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

FLAGS = -g -Wall -Werror -Wextra

SRCS = main.cpp Utils.cpp

SRCS_CMD = Command.cpp

SRCS_CMDS = help.cpp join.cpp kick.cpp nick.cpp notice.cpp part.cpp pass.cpp privmsg.cpp quit.cpp user.cpp who.cpp ping.cpp pong.cpp

SRCS_SC = Server.cpp Client.cpp

SRCS_CHAN = Channel.cpp

HEAD = Server.hpp Client.hpp

HEAD_UTILS = Utils.hpp Libraries.hpp Exceptions.hpp

HEAD_COMPO = Channel.hpp

HEAD_CMD = Command.hpp ListCommand.hpp

INCS = $(addprefix ./includes/network/, $(HEAD))

INCS_UTILS = $(addprefix ./includes/, $(HEAD_UTILS))

INCS_COMPO = $(addprefix .includes/network/components, $(HEAD_COMPO))

INCS_CMD = $(addprefix ./includes/commands/, $(HEAD_CMD))

OBJS = $(addprefix ./srcs/, $(SRCS:.cpp=.o))

OBJS_SC = $(addprefix ./srcs/network/, $(SRCS_SC))

OBJS_CHAN = $(addprefix ./srcs/network/components/, $(SRCS_CHAN))

OBJS_CMDS = $(addprefix ./srcs/commands/list/, $(SRCS_CMDS:.cpp=.o))

OBJS_CMD = $(addprefix ./srcs/commands/, $(SRCS_CMD:.cpp=.o))

$(NAME):	$(OBJS) $(OBJS_SC) $(OBJS_CHAN) $(OBJS_CMD) $(OBJS_CMDS)
			$(CC) $(FLAGS) $(OBJS) $(OBJS_SC) $(OBJS_CHAN) $(OBJS_CMD) $(OBJS_CMDS) -o $(NAME)

all:	$(NAME)

%.o:%.cpp	$(INCS_UTILS) $(INCS) $(INCS_COMPO) $(INCS_CMD)
			$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) srcs/*.o
		@$(RM) srcs/commands/*.o
		@$(RM) srcs/commands/list/*.o
		@$(RM) ircserv.dSYM
		@$(RM) *.o
		@printf "$(ERASE)$(RED)-> All files *.o cleaned$(END)\n"

fclean:	clean
		@$(RM) ircserv
		@printf "$(ERASE)$(RED)-> Executable cleaned$(END)\n"

re: fclean all clean

.PHONY: all clean fclean re