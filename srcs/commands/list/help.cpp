/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:56:04 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/09 01:21:28 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_help()
{
	cout << YELLOW << "Help exec function called!\n" << DEFAULT;

	vector<string> cmds;
    vector<string>::iterator it;

	vector<string> cmds_desc;
	vector<string>::iterator itd;
	
	cmds.push_back(JOIN);
	cmds.push_back(NICK);
	cmds.push_back(PART);
	cmds.push_back(PRIVMSG);
	cmds.push_back(NOTICE);
	cmds.push_back(QUIT);
	cmds.push_back(USER);
	cmds.push_back(KICK);
	cmds.push_back(PASS);
	cmds.push_back(WHO);
	cmds.push_back(PING);
	cmds.push_back(PONG);
	cmds.push_back(HELP);

	cmds_desc.push_back("/join - join a channel");
	cmds_desc.push_back("/nick - change nickname");
	cmds_desc.push_back("/part - to leave a channel");
	cmds_desc.push_back("/privmsg - send private message");
	cmds_desc.push_back("/notice - send private message without opening a priv msg window");
	cmds_desc.push_back("/quit - exit IRC session");
	cmds_desc.push_back("/user - define user (usage: /user <username> <hostname> <servername> <realname>)");
	cmds_desc.push_back("/kick - get rid of someone in given channel");
	cmds_desc.push_back("/pass - set a connection password");
	cmds_desc.push_back("/who - show who is on the IRC server or channel");
	cmds_desc.push_back("/ping - send from the server to test if client is alive");
	cmds_desc.push_back("/pong - response to ping");
	cmds_desc.push_back("/help - show general help or help on given command");

	itd = cmds_desc.begin();
	for (it = cmds.begin(); it != cmds.end(); it++)
	{
		_client->write(":server 705 - " + *itd);
		itd++;
	}
}