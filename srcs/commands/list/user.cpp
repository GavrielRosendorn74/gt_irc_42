/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:40 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 23:16:35 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_user()
{
    _server->log("/USER exec function called");
    if (!(_client->isRegistered()))
    {
        if (_args.size() == 4)
        {
            _client->setUsername(_args[0]);
            _client->setNickname(_args[3]);
            /* Send welcome message */
            _client->welcomeMsg();
        }
        _client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), USER));
        return ;
    }
    _client->reply(ERR_ALREADYREGISTERED(_client->getNickname()));
    return ;
}