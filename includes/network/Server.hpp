/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:34:36 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/07 07:26:42 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "../Libraries.hpp"
#include "components/Channel.hpp"
#include "Client.hpp"

using namespace std;

class Server
{
	typedef std::vector<pollfd>::iterator poll_it;
	typedef std::vector<Client *>::iterator client_it;
	typedef std::vector<Channel *>::iterator channel_it;
	
	private:
        int						_port;
		int                 	_option;
		string					_password;
		int						_sock_fd;
		string					_host;
		vector<Client *>		_clients;
		vector<Channel *>		_channels;
		vector<pollfd>			_fds;
		void					_onClientConnect();
		void					_onClientDisconnect(Client *client);
		void 					_onClientMessage(Client *client);
		std::string				_readMessageOfClient(Client *client);
	public:
		// CONSTRUCTORS
		Server(const string &port, const string &password);
		~Server();
		// FUNCTIONS
		void		log(string message);
		Server *	launch();
		void		live();
};


#endif