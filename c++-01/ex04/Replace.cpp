#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2)
{
}

Replace::~Replace(void)
{
}

/*
** std::string::replace is forbidden, so the new content is rebuilt by hand:
** find() locates the next occurrence, substr() copies the text before it, s2
** is appended, and the search resumes AFTER the occurrence. Because the
** result is built in a separate string, an s2 that contains s1 (replacing
** "a" with "aa") cannot loop forever.
*/
std::string Replace::substitute(const std::string& content) const
{
    std::string             result;
    std::string::size_type  start = 0;
    std::string::size_type  pos;

    if (this->_s1.empty())
        return (content);
    while ((pos = content.find(this->_s1, start)) != std::string::npos)
    {
        result += content.substr(start, pos - start);
        result += this->_s2;
        start = pos + this->_s1.length();
    }
    result += content.substr(start);
    return (result);
}

bool    Replace::run(void) const
{
    std::ifstream   infile(this->_filename.c_str());
    std::string     content;
    char            c;

    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open file '" << this->_filename << "'" << std::endl;
        return (false);
    }
    while (infile.get(c))
        content += c;
    infile.close();

    std::string     outname = this->_filename + ".replace";
    std::ofstream   outfile(outname.c_str());

    if (!outfile.is_open())
    {
        std::cerr << "Error: cannot create file '" << outname << "'" << std::endl;
        return (false);
    }
    outfile << this->substitute(content);
    outfile.close();
    return (true);
}
