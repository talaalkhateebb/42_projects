#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace
{
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;

        std::string substitute(const std::string& content) const;

    public:
        Replace(std::string filename, std::string s1, std::string s2);
        ~Replace(void);

        bool    run(void) const;
};

#endif
