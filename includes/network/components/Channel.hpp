/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:12:00 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 22:23:40 by tanguy           ###   ########.fr       */
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
	public:
		Channel(const std::string &name, Client *admin);
		~Channel();

		std::string					getName();
		std::vector<Client*>		*getClients();
		Client						*getAdmin();

		void						rmvClient(Client *client);
		void						addClient(Client *client);
		void						kick(Client *client, Client *target, std::string &comment);

		void 						broadcast(std::string const &message);



	private:
		string			 _name;
		Client 			*_admin;
		vector<Client *> _clients;
		Server 		 	*_server;
};

#endif