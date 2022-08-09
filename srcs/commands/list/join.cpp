/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:15 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 16:56:11 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_join()
{
    if (_args.empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "JOIN"));
		return;
	}

	string all_args = _args[0];
	string password = _args.size() > 1 ? _args[1] : "";

	while (all_args.find(',') != string::npos)
	{
		string name = all_args.substr(0, all_args.find(','));
		
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
		all_args = all_args.substr(all_args.find(',') + 1);
	}
	string name = all_args.substr(0, all_args.find(','));
		
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