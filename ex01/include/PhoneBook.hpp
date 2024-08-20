/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:58:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/13 19:26:56 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

# define CONFIRM_DELETE_CONTACT "Phonebook is full, this action will replace contact "

class PhoneBook
{
	private:
		class Contact	contacts[8];
		int				saved_contacts;

	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook(const PhoneBook &phonebook);
		PhoneBook &operator = (const PhoneBook &phonebook);
		void search_contact();
		void add_contact();
};

#endif