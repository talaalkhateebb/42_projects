#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

/*
** Reads one non-empty line from stdin. Returns false when the stream dies
** (Ctrl+D), so the caller can abort instead of looping forever.
*/
static bool	promptField(std::string const &label, std::string &out)
{
	while (true)
	{
		std::cout << label << ": ";
		if (!std::getline(std::cin, out))
			return (false);
		if (!out.empty())
			return (true);
		std::cout << "This field cannot be empty." << std::endl;
	}
}

/*
** Columns are 10 wide. Longer text is cut to 9 characters and the 10th
** becomes a dot, as required by the subject.
*/
static std::string	truncate(std::string const &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

PhoneBook::PhoneBook(void) : _count(0), _next(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!promptField("First name", firstName)
		|| !promptField("Last name", lastName)
		|| !promptField("Nickname", nickname)
		|| !promptField("Phone number", phoneNumber)
		|| !promptField("Darkest secret", darkestSecret))
		return ;
	this->_contacts[this->_next].set(firstName, lastName, nickname,
									 phoneNumber, darkestSecret);
	this->_next = (this->_next + 1) % MAX_CONTACTS;
	if (this->_count < MAX_CONTACTS)
		this->_count++;
	std::cout << "Contact saved." << std::endl;
}

void	PhoneBook::_displayHeader(void) const
{
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;
}

void	PhoneBook::_displayRow(int index) const
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(this->_contacts[index].getFirstName()) << "|"
			  << std::setw(10) << truncate(this->_contacts[index].getLastName()) << "|"
			  << std::setw(10) << truncate(this->_contacts[index].getNickname())
			  << std::endl;
}

void	PhoneBook::_displayContact(int index) const
{
	Contact const	&c = this->_contacts[index];

	std::cout << "First name    : " << c.getFirstName() << std::endl;
	std::cout << "Last name     : " << c.getLastName() << std::endl;
	std::cout << "Nickname      : " << c.getNickname() << std::endl;
	std::cout << "Phone number  : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

void	PhoneBook::search(void) const
{
	std::string	input;

	if (this->_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}
	this->_displayHeader();
	for (int i = 0; i < this->_count; ++i)
		this->_displayRow(i);
	std::cout << "Index to display: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	int	index = input[0] - '0';
	if (index < 0 || index >= this->_count)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	this->_displayContact(index);
}
