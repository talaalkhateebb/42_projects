#include "Contact.hpp"

Contact::Contact(void) : _isSet(false)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set(std::string const &firstName,
					 std::string const &lastName,
					 std::string const &nickname,
					 std::string const &phoneNumber,
					 std::string const &darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
	this->_isSet = true;
}

bool	Contact::isSet(void) const
{
	return (this->_isSet);
}

std::string const	&Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string const	&Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string const	&Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string const	&Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string const	&Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}
