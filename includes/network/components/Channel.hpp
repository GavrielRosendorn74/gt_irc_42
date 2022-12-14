/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:12:00 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/09 17:06:31 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "../../Libraries.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

# define NEWCHANNELADMIN(client)	client + "  is now the new administrator of this channel"
# define CLIENTKICKED(client)		client + " has been kicked from this channel : "
# define MSGBROADCASTEDTOCHANNEL(messages) message + " has been broadcasted to the channel"

using namespace std;

class Server;
class Client;

class Channel
{

	typedef vector<Client *>::iterator client_it;

	public:
		Channel(const std::string &name, Client *admin);
		~Channel();

		string				getName();
		vector<Client*>		*getClients();
		string				getClientsStr();

		Client						*getAdmin();
		void						setAdmin(Client *client){ _admin = client; }

		size_t		getMaxClients() const { return this->_len;};
		void		setMaxClients(size_t len) { this->_len = len;};
		size_t		getNumClients() const { return _clients.size();};

		void						rmvClient(Client *client);
		void						addClient(Client *client);
		void						kick(Client *client, Client *target, std::string &comment);

		void 						broadcast(std::string const &message, Client *_to_exclude);

		bool						isCLientInChannel(Client *client);

		client_it  					findClient(Client *client);



	private:
		size_t			 _len;
		string			 _name;
		Client 			*_admin;
		vector<Client *> _clients;
		Server 		 	*_server;
};

#endif