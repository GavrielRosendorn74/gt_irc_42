/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:17 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 02:05:15 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void Command::_kick()
{
    if (_args.size() < 2) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "KICK"));
		return;
	}

	std::string name = _args[0];
	std::string target = _args[1];
	std::string comment = "No reason specified.";

	if (_args.size() >= 3 && (_args[2][0] != ':' || _args[2].size() > 1)) {
		comment = "";
		for (std::vector<std::string>::iterator it = _args.begin() + 2; it != _args.end(); it++)
			comment.append(*it + " ");
	}

	Channel *channel = _server->findChannelByName(target.substr(1));;
	if (!channel || channel->getName() != name) {
		_client->reply(ERR_NOTONCHANNEL(_client->getNickname(), name));
		return;
	}

	if (channel->getAdmin() != _client) {
		_client->reply(ERR_CHANOPRIVSNEEDED(_client->getNickname(), name));
		return;
	}

	Client *dest = _server->findClientByNickname(target);
	if (!dest) {
		_client->reply(ERR_NOSUCHNICK(_client->getNickname(), target));
		return;
	}

	if (!dest->getChannel() || dest->getChannel() != channel) {
		_client->reply(ERR_USERNOTINCHANNEL(_client->getNickname(), dest->getNickname(), name));
		return;
	}

	channel->kick(_client, dest, comment);	
}