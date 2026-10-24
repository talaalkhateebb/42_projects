#include "Replace.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    if (std::string(argv[2]).empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return (1);
    }

    Replace sed(argv[1], argv[2], argv[3]);

    if (!sed.run())
        return (1);
    return (0);
}
