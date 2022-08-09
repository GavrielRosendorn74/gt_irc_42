/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:36 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 09:29:49 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_privmsg(){
	if (_args.size() < 2 || _args[0].empty() || _args[1].empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "PRIVMSG"));
		return;
	}

	std::string target = _args.at(0);
	std::string message = _args.at(1);

	message = message.at(0) == ':' ? message.substr(1) : message;

	if (target.at(0) == '#') {

		Channel *channel = _server->findChannelByName(target);
		
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

		channel->broadcast(RPL_PRIVMSG(_client->prefix(), target, message), _client);
		return;
	}

	Client *dest = _server->findClientByNickname(target);
	if (!dest) {
		_client->reply(ERR_NOSUCHNICK(_client->getNickname(), target));
		return;
	}

	dest->write(RPL_PRIVMSG(_client->prefix(), target, message));

}