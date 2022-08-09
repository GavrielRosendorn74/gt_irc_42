/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:25 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 15:25:07 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/commands/Command.hpp"

void Command::_part(){
	if (_args.empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "PART"));
		return;
	}

	string all_arg = _args[0];
	while (all_arg.find(',') != string::npos) 
	{
		string name = all_arg.substr(0, all_arg.find(','));
		Channel *channel = _server->findChannelByName(name);
		if (!channel) {
			_client->reply(ERR_NOSUCHCHANNEL(_client->getNickname(), name));
		} else {
			channel->rmvClient(_client);
		}
		all_arg = all_arg.substr(all_arg.find(',') + 1);
	}
	string name = all_arg.substr(0, all_arg.find(','));
	Channel *channel = _server->findChannelByName(name);
	if (!channel) {
		_client->reply(ERR_NOSUCHCHANNEL(_client->getNickname(), name));
		return;
	} else {
		channel->rmvClient(_client);
	}
}