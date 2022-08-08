/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:28:14 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/08 18:51:48 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

void    Command::_nick()
{
    if (!(_args.empty()))
    {
        _client->setNickname(_args[0]);
        _client->welcomeMsg();
    }
    //* REPLY FUNCTION TO RETURN REPLY CODE -> args error
}