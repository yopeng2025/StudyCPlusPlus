#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class   Harl
{
    private:
        typedef void    (Harl::*HarlFunction)(void);

        //static = shared
        static const    HarlFunction functions[4];
        static const    std::string levels[4];

        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        void    complain(std::string level);
};

#endif