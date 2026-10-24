#include "Zombie.hpp"

/*
** The zombie is used and finished inside this function, so the stack is the
** right place: it is destroyed automatically at the closing brace and there
** is nothing to delete.
*/
void    randomChump(std::string name)
{
    Zombie  chump(name);

    chump.announce();
}
