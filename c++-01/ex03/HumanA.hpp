#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

/*
** HumanA always has a weapon and receives it at construction, so the weapon
** can never be absent and never has to be replaced: a reference is the exact
** tool for that. It is bound in the constructor's initialisation list.
*/
class HumanA
{
    private:
        std::string _name;
        Weapon&     _weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);

        void    attack(void) const;
};

#endif
