/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:12:00 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 08:17:33 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"
#include "../Client.hpp"
#include <vector>
#include <iostream>

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

using namespace std;

class Channel
{
	public:
		Channel(Server *server);
		~Channel();
	private:
		Client *		 _admin;
		vector<Client *> _clients;
		Server *		 _server;
};

#endif