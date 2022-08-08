/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:53:48 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/08 18:32:49 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network/Client.hpp"

Client::Client(int port, pollfd *fd, const std::string &hostname) : _port(port), _pollfd(fd), _hostname(hostname), _channel(nullptr) {}

Client::~Client() {}

void    Client::join(Channel *channel)
{
    channel->addClient(this);
    _channel = channel;

    //* get channe users function -> store it in a vector  */

    //* announce to channel that this client user has arrived */
}

void    Client::welcomeMsg()
{
    if (_username.empty() || _nickname.empty() || _realname.empty())
        throw Exception::user_registration_args_error();

    _role = CONNECTED;
    //* display welcome message HERE
    //* user now know as "NEW NICKNAME"
}