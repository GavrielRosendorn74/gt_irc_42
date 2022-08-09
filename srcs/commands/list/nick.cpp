/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:28:14 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/09 07:10:12 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_nick()
{
    _server->log("/NICK exec function called");
    if (!(_args.empty()))
    {
        std::string nick = _args[0];
        if (!(_server->findClientByNickname(nick)))
        {
            _client->setNickname(_args[0]);
        } else 
        	_client->reply(ERR_NICKNAMEINUSE(_client->getNickname()));
        return ;
    }
    _client->reply(ERR_NONICKNAMEGIVEN(_client->getNickname()));
    return ;
}