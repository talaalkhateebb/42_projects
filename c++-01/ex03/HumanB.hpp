#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

/*
** HumanB may have no weapon at all, and can be given one later. "No weapon"
** and "this weapon instead" are states only a pointer can express, so the
** member is a Weapon* initialised to NULL.
*/
class HumanB
{
    private:
        std::string _name;
        Weapon*     _weapon;

    public:
        HumanB(std::string name);
        ~HumanB(void);

        void    setWeapon(Weapon& weapon);
        void    attack(void) const;
};

#endif
