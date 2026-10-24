#include "Zombie.hpp"

/*
** One single allocation for the whole horde: new Zombie[N] reserves one
** contiguous block of N objects. It must therefore be released with
** delete[], never with delete.
*/
Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde;

    if (N <= 0)
        return (NULL);
    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}
