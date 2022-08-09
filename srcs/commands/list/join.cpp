/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:15 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 02:26:40 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_join()
{
    if (_args.empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "JOIN"));
		return;
	}

	std::string name = _args[0];
	std::string password = _args.size() > 1 ? _args[1] : "";

	Channel *channel = _server->findChannelByName(name);
	if (channel) {
		_client->reply(ERR_TOOMANYCHANNELS(_client->getNickname(), name));
		return;
	}

	channel = _server->findChannelByName(name);
	if (!channel)
		channel = _server->createChannel(name, _client);

	if (channel->getMaxClients() > 0 && channel->getNumClients() >= channel->getMaxClients()){
		_client->reply(ERR_CHANNELISFULL(_client->getNickname(), name));
		return;
	}

	_client->join(channel);	
}