/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:58:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/12 18:11:17 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		saved_contacts;

	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook(const PhoneBook &phonebook);
		PhoneBook &operator = (const PhoneBook &phonebook);
		void search_contact();
		void add_contact();
};

#endif