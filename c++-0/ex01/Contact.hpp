#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void				set(std::string const &firstName,
								std::string const &lastName,
								std::string const &nickname,
								std::string const &phoneNumber,
								std::string const &darkestSecret);

		bool				isSet(void) const;

		std::string const	&getFirstName(void) const;
		std::string const	&getLastName(void) const;
		std::string const	&getNickname(void) const;
		std::string const	&getPhoneNumber(void) const;
		std::string const	&getDarkestSecret(void) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		bool		_isSet;
};

#endif
