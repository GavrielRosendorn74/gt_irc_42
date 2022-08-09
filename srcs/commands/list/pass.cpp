/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:28 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 07:23:13 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_pass()
{
    _server->log("/PASS exec function called");
    if (_client->getRole() == ANONYMOUS)
    {
		_server->log("server password is : " + _server->getPassword());
		_server->log("client password is : " + _args[0]);
        if (!(_args.empty()))
        {
            if (_server->getPassword() == _args[0])
                _client->setRole(ANONYMOUS_WITH_GOOD_PASSWORD);
            else
            {
                _client->reply(ERR_PASSWDMISMATCH(_client->getNickname()));
                return ;
            }
        }
        else
        {
            _client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), PASS));
            return ;
        }
    }
    else
    {
        _client->reply(ERR_ALREADYREGISTERED(_client->getNickname()));
        return ;
    }
}