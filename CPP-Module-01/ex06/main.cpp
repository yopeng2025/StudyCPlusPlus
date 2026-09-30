#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }

    std::string input_level = argv[1];
    Harl    harl;

    int         level_index = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == input_level)
        {
            level_index = i;
            break ;
        }
    }

    switch (level_index)
    {
        case 0:
            std::cout << "[DEBUG]" << std::endl;
            harl.complain("DEBUG");
        case 1:
            std::cout << "[INFO]" << std::endl;
            harl.complain("INFO");
        case 2:
            std::cout << "[WARNING]" << std::endl;
            harl.complain("WARNING");
        case 3:
            std::cout << "[ERROR]" << std::endl;
            harl.complain("ERROR");
            break ;
        default:
            std::cout << "[Probably complaining about insignificant problems]" << std::endl;
    }
}