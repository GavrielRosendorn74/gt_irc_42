/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:37:56 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 02:27:04 by grosendo         ###   ########.fr       */
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
	_command = "";
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
			return (this);
		}
	} else _prefix = "";
	// SKIP SPACES
	index = 0;
	while (raw[index] == ' ') index++;
	raw = raw.substr(index);
	// GET COMMAND
	if (raw.find(' ') != string::npos) {
		_command = raw.substr(0, raw.find(' '));
		raw = raw.substr(raw.find(' '));
	} else {
		_command = raw;
		return (this);
	}
	// GET ARGS
	while (1)
	{
		// SKIP SPACES
		index = 0;
		while (raw[index] == ' ') index++;
		raw = raw.substr(index);
		// SECURITY EMPTY ARG
		if (raw.length() == 0)
			break ;
		// VERIFY IF FINAL ARG
		if (raw[0] == ':')
		{
			_args.push_back(raw.substr(1));
			break ;
		// IF NOT LAST ARG
		} else if (raw.find(' ') != string::npos) {
			_args.push_back(raw.substr(0, raw.find(' ')));
			raw = raw.substr(raw.find(' '));
		// IF LAST ARG
		} else {
			_args.push_back(raw);
			break ;
		}
	}
	return (this);
}

void Command::printParsing()
{
	_server->log("PREFIX : " + _prefix);
	_server->log("COMMAND : " + _command);
	int index = 0;
	for (str_it it = _args.begin(); it != _args.end(); it++) {
		_server->log("ARGS [" + ft_itoastr(index) +  "] : " + (*it));
		index ++;
	}
}

void Command::execute()
{
	printParsing();
	if (!_redirectExec())
		_client->reply(ERR_UNKNOWNCOMMAND(_client->getNickname(), _command));
}

bool isValidCmd(std::string command)
{
	if (command == JOIN || command == NICK || command == PART ||
		command == PRIVMSG || command == NOTICE || command == QUIT ||
		command == USER || command == KICK || command == PASS || command == WHO ||
		command == PING || command == PONG || command == HELP)
		return true;
	return false;
}

bool Command::_redirectExec(void)
{
	if (isValidCmd(_command))
	{
		if (_command == JOIN)
			_join();
		if (_command == HELP)
			_help();
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
