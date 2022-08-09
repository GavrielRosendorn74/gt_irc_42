/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:22 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 01:58:23 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_notice()
{
	if (_args.size() < 2 || _args[0].empty() || _args[1].empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "PRIVMSG"));
		return;
	}

	std::string target = _args.at(0);
	std::string message;

	for (std::vector<std::string>::iterator it = _args.begin() + 1; it != _args.end(); it++) {
		message.append(*it + " ");
	}

	message = message.at(0) == ':' ? message.substr(1) : message;

	if (target.at(0) == '#') {

		Channel *channel = _server->findChannelByName(target.substr(1));
		
		if (!channel) {
			_client->reply(ERR_NOSUCHCHANNEL(_client->getNickname(), target));
			return;
		}

		vector<Client *>		clients = *channel->getClients();
		client_it				i;
		
		for (i = clients.begin(); i != clients.end(); i++)
			if (*i == _client)
				break;
		if (i == clients.end())
		{
			_client->reply(ERR_CANNOTSENDTOCHAN(_client->getNickname(), target));
			return;
		}

		channel->broadcast(RPL_NOTICE(_client->prefix(), target, message), _client);
		return;
	}

	Client *dest = _server->findClientByNickname(target);
	if (!dest) {
		_client->reply(ERR_NOSUCHNICK(_client->getNickname(), target));
		return;
	}

	dest->write(RPL_NOTICE(_client->prefix(), target, message));
}