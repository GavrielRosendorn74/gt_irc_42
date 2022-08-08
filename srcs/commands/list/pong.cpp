/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:33 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 19:25:17 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

void    Command::_pong()
{
    if (!(_args.empty()))
        //* write pong
        _client->write(RPL_PING(_client->getPrefix(), arguments.at(0)));
    else
        //* REPLY() args error

}