/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:58:39 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/07 07:02:55 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libraries.hpp"

string ft_itoastr(int nbr)
{
	string str;
	stringstream ss;
  	ss << nbr;  
  	ss >> str; 
	return (str);
}