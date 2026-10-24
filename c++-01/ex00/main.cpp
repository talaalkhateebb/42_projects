#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- heap: newZombie() ---" << std::endl;
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    std::cout << std::endl << "--- stack: randomChump() ---" << std::endl;
    randomChump("Chumpy");

    std::cout << std::endl << "--- stack: plain scope ---" << std::endl;
    {
        Zombie  stackZombie("Stacky");
        stackZombie.announce();
    }

    std::cout << std::endl << "--- end of main ---" << std::endl;
    return (0);
}
