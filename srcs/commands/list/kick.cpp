/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:17 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 15:48:51 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void Command::_kick()
{
    if (_args.size() < 2) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "KICK"));
		return;
	}

	std::string chanName = _args[0]; // channel name
	std::string target = _args[1]; // clienrt to kick out 
	std::string comment = "No reason specified.";

	if (_args.size() >= 3 && (_args[2][0] != ':' || _args[2].size() > 1)) {
		comment = "";
		for (std::vector<std::string>::iterator it = _args.begin() + 2; it != _args.end(); it++)
			comment.append(*it + " ");
	}

	Channel *channel = _server->findChannelByName(chanName.substr(0)); // fin channel without #
	if (!channel || channel->getName() != chanName) {
		_client->reply(ERR_NOTONCHANNEL(_client->getNickname(), chanName));
		return;
	}

	if (channel->getAdmin() != _client) {
		_client->reply(ERR_CHANOPRIVSNEEDED(_client->getNickname(), chanName));
		return;
	}

	Client *dest = _server->findClientByNickname(target);
	if (!dest) {
		_client->reply(ERR_NOSUCHNICK(_client->getNickname(), target));
		return;
	}

	channel->kick(_client, dest, comment);	
}