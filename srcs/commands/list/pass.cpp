/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:28 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 19:29:58 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

void    Command::_pass()
{
    _server->log("/PASS exec function called");
    if (!(_client->isRegistered()))
    {
        if (!(_args.empty()))
        {
            if (_server->getPassword() == _args[0])
                _client->setRole(CONNECTED);
            //* REPLY FUNCTION TO RETURN REPLY CODE -> invalid pswd
        }
        //* REPLY FUNCTION TO RETURN REPLY CODE -> args error
    }
    //* REPLY FUNCTION TO RETURN REPLY CODE -> user already registered
}