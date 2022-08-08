/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:33 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 01:02:01 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_pong()
{
	if (_args.empty()) {
		_client->reply(ERR_NEEDMOREPARAMS(_client->getNickname(), "PONG"));
		return;
	}

	_client->write(RPL_PING(_client->prefix(), _args.at(0)));

}