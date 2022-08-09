/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:34:36 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 09:53:11 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "../Libraries.hpp"
#include "components/Channel.hpp"
#include "Client.hpp"

class Client;
class Channel;

using namespace std;

typedef vector<pollfd>::iterator poll_it;
typedef vector<Client *>::iterator client_it;
typedef vector<Channel *>::iterator channel_it;

class Server
{	
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
		string					_readMessageOfClient(Client *client);
	public:
		// CONSTRUCTORS
		Server(const string &port, const string &password);
		~Server();
		// FUNCTIONS
		string					getPassword();
		Client *				findClientByNickname(string nickname);
		Client *				findClientByFd(pollfd fd);
		Channel *				findChannelByName(string name);
		Channel *				createChannel(string name, Client *client);
		client_it				findClient(Client *client);
		channel_it				findChannel(Channel *channel);
		void					removeChannel(Channel *channel);
		poll_it					findFd(pollfd fd);
		vector<Client *>		getClients();
		void					log(string message);
		Server *				launch();
		void					live();
};


#endif