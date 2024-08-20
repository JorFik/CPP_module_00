/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:41 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 12:25:17 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}
std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

void Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}
void Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::clear()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}
