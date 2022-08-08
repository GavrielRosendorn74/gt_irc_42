/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:25:40 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 18:35:04 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../network/Server.hpp"
#include "../network/Client.hpp"
#include <vector>
#include <iostream>

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "ListCommand.hpp"

using namespace std;

class Command
{

    public:
        Command(Server *server, Client *client);
		Command *build(string raw);
		void execute();
        ~Command();
    private:
		vector<string>	_args;
        Client *		_client;
        Server *		_server;
		string 			_prefix;
		string			_command;
		// FUNCTIONS
		bool			_redirectExec(void);
		// COMMANDS
		void			_join();
		void			_nick();
		void			_mode();
		void			_part();
		void			_privmsg();
		void			_notice();
		void			_quit();
		void			_user();
		void			_ping();
		void			_pong();
		void			_kick();
		void			_pass();
};

#endif