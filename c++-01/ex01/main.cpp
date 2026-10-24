#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    int     N = 5;
    Zombie* horde;

    std::cout << "--- horde of " << N << " ---" << std::endl;
    horde = zombieHorde(N, "Horde");
    if (horde == NULL)
    {
        std::cout << "zombieHorde() failed." << std::endl;
        return (1);
    }
    for (int i = 0; i < N; i++)
        horde[i].announce();

    std::cout << std::endl << "--- deleting the horde ---" << std::endl;
    delete [] horde;

    std::cout << std::endl << "--- edge case: N = 0 ---" << std::endl;
    horde = zombieHorde(0, "Nobody");
    std::cout << "returned " << (horde == NULL ? "NULL" : "something") << std::endl;
    delete [] horde;

    std::cout << std::endl << "--- edge case: N = -3 ---" << std::endl;
    horde = zombieHorde(-3, "Nobody");
    std::cout << "returned " << (horde == NULL ? "NULL" : "something") << std::endl;
    delete [] horde;

    return (0);
}
