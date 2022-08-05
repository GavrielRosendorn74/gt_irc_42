/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:37:56 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 08:49:44 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(Server *server, Client *client)
{
	_server = server;
	_client = client;
}

Command::~Command(){}

// RAW HAVE TO BE ONLY ONE LINE THERE ! No \n or \r please parse it before

Command *Command::build(string raw)
{
	raw.
}