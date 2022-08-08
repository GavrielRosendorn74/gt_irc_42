/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:37:56 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 20:03:22 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Command::Command(Server *server, Client *client)
{
	_server = server;
	_client = client;
}

Command::~Command(){}

// RAW HAVE TO BE ONLY ONE LINE THERE ! No \n or \r please parse it before

Command *Command::build(string raw)
{
	raw.
}

bool Command::_redirectExec(void)
{
	if (_command == JOIN)
		_join();
	if (_command == NICK)
		_nick();
	if (_command == PART)
		_part();
	if (_command == PRIVMSG)
		_privmsg();
	if (_command == NOTICE)
		_notice();
	if (_command == QUIT)
		_quit();
	if (_command == USER)
		_user();
	if (_command == KICK)
		_kick();
	if (_command == PASS)
		_pass();
	if (_command == WHO)
		_who();
	if (_command == PING)
		_ping();
	if (_command == PONG)
		_pong();
}