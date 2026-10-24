#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;

	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_count;
		int		_next;

		void	_displayHeader(void) const;
		void	_displayRow(int index) const;
		void	_displayContact(int index) const;
};

#endif
