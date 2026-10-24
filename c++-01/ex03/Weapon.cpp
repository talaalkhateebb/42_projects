#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

/*
** Returning a const reference means no copy is made: the caller always sees
** the current value of _type, which is why an attack made after setType()
** shows the new weapon. const forbids modifying _type behind the setter.
*/
const std::string&  Weapon::getType(void) const
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}
