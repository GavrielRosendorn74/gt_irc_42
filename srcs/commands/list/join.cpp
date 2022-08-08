/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:15 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 01:02:41 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_join()
{
    if (_args.empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "PASS"));
		return;
	}

	std::string name = _args[0];
	std::string password = _args.size() > 1 ? _args[1] : "";

	Channel *channel = _client->getChannel();
	if (channel) {
		_client->reply(ERR_TOOMANYCHANNELS(_client->getNickname(), name));
		return;
	}

	channel = _server->getChannel(name);
	if (!channel)
		channel = _server->createChannel(name, password, _client);

	if (channel->getMaxClients() > 0 && channel->getNumClients() >= channel->getMaxClients()){
		_client->reply(ERR_CHANNELISFULL(_client->getNickname(), name));
		return;
	}

	_client->join(channel);	
}