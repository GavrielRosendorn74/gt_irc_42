/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:40 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 18:51:39 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

void    Command::_user()
{
    if (!(_client->isRegistered()))
    {
        if (_args.size() == 4)
        {
            _client->setUsername(_args[0]);
            _client->setNickname(_args[3]);
            /* Send welcome message */
            _client->welcomeMsg();
        }
        //* REPLY FUNCTION TO RETURN REPLY CODE -> args error
    }
    //* REPLY FUNCTION TO RETURN REPLY CODE -> user already registered
}