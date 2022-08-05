/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:25:40 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 05:12:50 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

#ifndef COMMAND_HPP
# define COMMAND_HPP

using namespace std;

class Command
{

    public:
        Command(Server *server, Client *client);
        ~Command();

    private:
		std::vector<std::string> _args;
        Client         *_client;
        Server         *_server;
};

#endif