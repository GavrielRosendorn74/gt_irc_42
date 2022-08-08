/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:01:35 by tanguy            #+#    #+#             */
/*   Updated: 2022/08/08 20:35:10 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"
/*
vector<Client*> *getUsersFromChannel(Channel *channel)
{
    vector<Client*> users;
    if (channel == NULL) // check if channel exists
        return NULL;
    return channel->getMembers(); // if it exists -> return members of it
}
*/
void    Command::_who()
{/*
    _server->log("/WHO exec function called");
    if (!(_args.empty())) // if _args are not empty -> then list users in channel corresponding to _args[0]
    {
        // check if channel provided exists ?
         vector<Client*> *users;
        if (!(users = getUsersFromChannel(_server->findChannel(_args[0]))))
            //* REPLY() error no such channel
        else
        {
            vector<Client*>::iterator   uit = users->begin();
            for (; uit < users->end(); uit++)
                //* REPLY() to display users in channel
        }
        
    }
    // otherwise list clients present in sever by fetching them and displaying them
    vector<Client*>             users = _server->getClients(); // function to fecth clients from current server -> vector of clients
    vector<Client*>::iterator   uit = users.begin();
    for(; uit < users.end(); uit++)
        //* REPLY() to display users in server*/
}