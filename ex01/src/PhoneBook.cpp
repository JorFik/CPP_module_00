/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:13:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/12 19:48:42 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	clean_cin_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PhoneBook::add_contact()
{
	const int contact_index = saved_contacts % 8;
	std::string answer;

	if (saved_contacts >= 8)
	{
		std::cout << "Phonebook is full, this action will replace contact ";
		std::cout << contact_index + 1 << std::endl;
		std::cout << "Do you want to continue? [y/N]: ";
		std::getline(std::cin, answer);
		if (answer != "y")
			return (clean_cin_buffer());
	}
	std::cout << "Creating new contact\n\tFirst name: " << std::flush;
	std::getline(std::cin, contacts[contact_index].first_name);
	std::cout << "\tLast name: " << std::flush;
	std::getline(std::cin, contacts[contact_index].last_name);
	std::cout << "\tNickname: " << std::flush;
	std::getline(std::cin, contacts[contact_index].nickname);
	std::cout << "\tPhone number: " << std::flush;
	std::getline(std::cin, contacts[contact_index].phone_number);
	std::cout << "\tDarkest secret: " << std::flush;
	std::getline(std::cin, contacts[contact_index].darkest_secret);
	std::cout << "Contact saved";
	saved_contacts++;
	clean_cin_buffer();
}

void	print_in_columns(std::string str, std::string column_separator)
{
	const int	str_len = str.length();

	if (str_len > 10)
		std::cout << str.substr(0, 9) << "." << column_separator;
	else
		std::cout << std::setw(10) << str << column_separator;
}

void	print_all_contacts(Contact contacts[8], int max_contacts)
{
	print_in_columns("Index", "|");
	print_in_columns("First name", "|");
	print_in_columns("Last name", "|");
	print_in_columns("Nickname", "\n");
	for (int i = 0; i < max_contacts; i++)
	{
		print_in_columns(std::to_string(i + 1), "|");
		print_in_columns(contacts[i].first_name, "|");
		print_in_columns(contacts[i].last_name, "|");
		print_in_columns(contacts[i].nickname, "");
		std::cout << std::endl;
	}
}

void	PhoneBook::search_contact()
{
	std::string index_str;
	int	index;
	int	max_contacts;

	if (saved_contacts == 0)
		return (std::cout << "No contacts saved\n", (void)0);
	max_contacts = saved_contacts;
	if (max_contacts > 8)
		max_contacts = 8;
	print_all_contacts(contacts, max_contacts);
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, index_str);
	if (std::cin.eof() || index_str.empty())
		return (std::cout << "Invalid index" << std::flush, clean_cin_buffer());
	index = std::stoi(index_str);
	if (index < 1 || index > max_contacts)
		return (std::cout << "Invalid index" << std::flush, clean_cin_buffer());
	index--;
	std::cout << "First name: " << contacts[index].first_name << "\n";
	std::cout << "Last name: " << contacts[index].last_name << "\n";
	std::cout << "Nickname: " << contacts[index].nickname << "\n";
	std::cout << "Phone number: " << contacts[index].phone_number << "\n";
	std::cout << "Darkest secret: " << contacts[index].darkest_secret;
	std::cout << std::flush;
	clean_cin_buffer();
}

PhoneBook::PhoneBook()
{
	saved_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook(const PhoneBook &phonebook)
{
	int	i;
	int	max_contacts;

	saved_contacts = phonebook.saved_contacts;
	max_contacts = saved_contacts;
	if (max_contacts > 8)
		max_contacts = 8;
	i = -1;
	while (++i < max_contacts)
		contacts[i] = phonebook.contacts[i];
}

PhoneBook &PhoneBook::operator = (const PhoneBook &phonebook)
{
	int	i;
	int	max_contacts;

	saved_contacts = phonebook.saved_contacts;
	max_contacts = saved_contacts;
	if (max_contacts > 8)
		max_contacts = 8;
	i = -1;
	while (++i < saved_contacts)
		contacts[i] = phonebook.contacts[i];
	return (*this);
}
