/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:25 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 02:16:08 by grosendo         ###   ########.fr       */
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
		if (name[0] != '#')
			continue;
		name = name.substr(1);
		Channel *channel = _server->findChannelByName(name);
		if (!channel) {
			_client->reply(ERR_NOSUCHCHANNEL(_client->getNickname(), name));
			continue;
		}
		all_arg = all_arg.substr(all_arg.find(',') + 1);
	}
	string name = all_arg.substr(0, all_arg.find(','));
	if (name[0] != '#')
		return ;
	name = name.substr(1);
	Channel *channel = _server->findChannelByName(name);
	if (!channel) {
		_client->reply(ERR_NOSUCHCHANNEL(_client->getNickname(), name));
		return;
	}
}