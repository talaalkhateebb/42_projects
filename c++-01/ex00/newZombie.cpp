#include "Zombie.hpp"

/*
** The zombie has to survive the end of this function, so it cannot live on
** the stack: a stack object is destroyed at the closing brace and the caller
** would receive a pointer to dead memory. It is allocated on the heap and
** the caller becomes responsible for deleting it.
*/
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}
