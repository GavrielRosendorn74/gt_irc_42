/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:40 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 07:44:26 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_user()
{
    _server->log("/USER exec function called");
	if (_client->getRole() == ANONYMOUS_WITH_GOOD_PASSWORD)
    {
        if (_args.size() >= 4)
        {
            _client->setUsername(_args[0]);
            _client->setRealname(_args[3]);
            /* Send welcome message */
            _client->welcomeMsg();
        } else 
        	_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), USER));
        return ;
    } else if (_client->getRole() == ANONYMOUS) {
    	_client->reply(ERR_PASSWDMISMATCH(_client->getNickname()));
	} else
    	_client->reply(ERR_ALREADYREGISTERED(_client->getNickname()));
    return ;
}