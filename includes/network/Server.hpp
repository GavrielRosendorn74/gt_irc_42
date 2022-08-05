/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:34:36 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 05:11:07 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

#ifndef SERVER_HPP
# define SERVER_HPP

using namespace std;

class Server
{
	public:
		// CONSTRUCTORS
		Server(string &port, const string &password);
		~Server();
		// FUNCTIONS
		void		log(string message);
		void		launch();
		void		onClientConnect();
		void		onClientDisconnect(Client *client);
		void 		onClientMessage(Client *client);
		std::string	readMessageOfClient(Client *client);
	private:
		const string			_port;
		const string			_password;
		int						_sock_fd;
		const string			_host;
		vector<Client *>		_clients;
		std::vector<Channel *>	_channels;
};


#endif