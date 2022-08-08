/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:38 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 18:50:04 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

void    Command::_quit()
{
    std::string comment;
    if (_args.empty())
        comment = "Leaving...";
    else
        comment = _args.at(0);
    
    //* REPLY FUNCTION TO RETURN REPLY CODE
    //* client write message and send REPLY code to quit server
}