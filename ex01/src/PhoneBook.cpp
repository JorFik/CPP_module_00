/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:13:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 12:53:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	clean_cin_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool	request_confirmation(std::string message)
{
	std::string answer;

	std::cout << message << std::endl;
	std::cout << "Do you want to continue? [y/N]: " << std::flush;
	std::getline(std::cin, answer);
	if (answer == "y" || answer == "Y")
		return (true);
	else if (answer == "N" || answer == "n")
		return (false);
	std::cout << "Invalid input" << std::flush;
	return (request_confirmation(message));
}

enum ContactField
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

int	get_contact_input(enum ContactField field, class Contact *contact)
{
	const char	*prompt[5] =
		{"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string user_input;

	std::cout << "\t" << prompt[field] << ": " << std::flush;
	std::getline(std::cin, user_input);
	if (std::cin.eof() || user_input.empty())
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "The contact will not be saved" << std::endl;
		clean_cin_buffer();
		contact->clear();
		return (1);
	}
	if (field == FIRST_NAME)
		contact->set_first_name(user_input);
	else if (field == LAST_NAME)
		contact->set_last_name(user_input);
	else if (field == NICKNAME)
		contact->set_nickname(user_input);
	else if (field == PHONE_NUMBER)
		contact->set_phone_number(user_input);
	else if (field == DARKEST_SECRET)
		contact->set_darkest_secret(user_input);
	return (0);
}

void PhoneBook::add_contact()
{
	const int contact_index = saved_contacts % 8;
	std::pair<bool, std::string> input;

	if (saved_contacts >= 8
		&& !request_confirmation(CONFIRM_DELETE_CONTACT
			+ std::to_string(contact_index + 1)))
			return (clean_cin_buffer());
	std::cout << "Creating new contact" << std::endl;
	if (get_contact_input(FIRST_NAME, &contacts[contact_index]))
		return ;
	if (get_contact_input(LAST_NAME, &contacts[contact_index]))
		return ;
	if (get_contact_input(NICKNAME, &contacts[contact_index]))
		return ;
	if (get_contact_input(PHONE_NUMBER, &contacts[contact_index]))
		return ;
	if (get_contact_input(DARKEST_SECRET, &contacts[contact_index]))
		return ;
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
		print_in_columns(contacts[i].get_first_name(), "|");
		print_in_columns(contacts[i].get_last_name(), "|");
		print_in_columns(contacts[i].get_nickname(), "");
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
		return (std::cout << "Invalid index" << std::endl, clean_cin_buffer());
	index = std::stoi(index_str);
	if (index < 1 || index > max_contacts)
		return (std::cout << "Invalid index" << std::flush, clean_cin_buffer());
	index--;
	std::cout << "First name: " << contacts[index].get_first_name() << "\n";
	std::cout << "Last name: " << contacts[index].get_last_name() << "\n";
	std::cout << "Nickname: " << contacts[index].get_nickname() << "\n";
	std::cout << "Phone number: " << contacts[index].get_phone_number() << "\n";
	std::cout << "Darkest secret: " << contacts[index].get_darkest_secret();
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
