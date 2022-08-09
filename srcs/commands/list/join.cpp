/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:15 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 14:53:43 by tanguy           ###   ########.fr       */
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

	if (!channel)
		channel = _server->createChannel(name, _client);

	if (channel->getMaxClients() > 0 && channel->getNumClients() >= channel->getMaxClients()){
		_client->reply(ERR_CHANNELISFULL(_client->getNickname(), name));
		return;
	}

	if (channel->isCLientInChannel(_client))
	{
		_client->reply(ERR_USERONCHANNEL(_client->getNickname(), channel->getName()));
		return ;
	}

	_client->join(channel);	
	_client->write(RPL_NAMREPLY(_client->getNickname(), channel->getName(), channel->getClientsStr()));
	_client->write(RPL_ENDOFNAMES(_client->getNickname(), channel->getName()));
}