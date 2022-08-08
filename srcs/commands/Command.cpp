/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:37:56 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 22:10:58 by grosendo         ###   ########.fr       */
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
	int index = 0;
	// SKIP SPACES
	while (raw[index] == ' ') index++;
	raw = raw.substr(index);
	// GET PREFIX
	if (raw[0] == ':') {
		if (raw.find(' ') != string::npos) {
			_prefix = raw.substr(0, raw.find(' '));
			raw = raw.substr(raw.find(' '));
		} else {
			_prefix = raw;
		}
	} else _prefix = "";
	
	_command = "";
	_args.push_back("");
	return (this);
}

void Command::execute()
{

}

bool isValidCmd(std::string command)
{
	if (command == JOIN || command == NICK || command == PART ||
		command == PRIVMSG || command == NOTICE || command == QUIT ||
		command == USER || command == KICK || command == PASS || command == WHO ||
		command == PING || command == PONG)
		return true;
	return false;
}

bool Command::_redirectExec(void)
{
	if (isValidCmd(_command))
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
		return true;
	}
	return false;
}
