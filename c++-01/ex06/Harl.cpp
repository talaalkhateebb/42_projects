#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle"
                 "-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't "
                 "put enough bacon in my burger! If you did, I wouldn't be asking "
                 "for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been "
                 "coming for years, whereas you started working here just last "
                 "month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*
** switch only accepts an integral value, never a std::string, so the level
** name is turned into an index first. -1 means "unknown" and lands in default.
*/
int     Harl::getLevel(std::string level) const
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return (i);
    }
    return (-1);
}

/*
** The missing break statements are deliberate. Matching a case falls through
** into every case below it, so the requested level and all the more severe
** ones are printed. Only the last case breaks.
*/
void    Harl::complain(std::string level)
{
    switch (this->getLevel(level))
    {
        case 0:
            this->debug();
            /* fall through */
        case 1:
            this->info();
            /* fall through */
        case 2:
            this->warning();
            /* fall through */
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break ;
    }
}
