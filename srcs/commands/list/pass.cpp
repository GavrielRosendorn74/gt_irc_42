/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:28 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 23:20:57 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_pass()
{
    _server->log("/PASS exec function called");
    if (!(_client->isRegistered()))
    {
        if (!(_args.empty()))
        {
            if (_server->getPassword() == _args[0])
                _client->setRole(CONNECTED);
            _client->reply(ERR_PASSWDMISMATCH(_client->getNickname()));
            return ;
        }
        _client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), PASS));
        return ;
    }
    _client->reply(ERR_ALREADYREGISTERED(_client->getNickname()));
    return ;
}