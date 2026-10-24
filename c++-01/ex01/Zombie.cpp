#include "Zombie.hpp"
#include <iostream>

/*
** new Zombie[N] default-constructs every element and cannot forward any
** argument, so a default constructor is mandatory here and the names are
** set afterwards through setName().
*/
Zombie::Zombie(void) : _name("")
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << ": is destroyed." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
