#include "BitcoinExchange.hpp"

int     main(int ac, char **av)
{
    (void)av;
    if (ac != 2 )
    {
        std::cerr << "Error: This program requiered 1 argument. Try : ./btc input.csv" << std::endl;
        return (0);
    }
    std::map<std::string, float> datafile;
    try {
        stockDatafile(datafile);
        ft_convert(av[1], datafile);
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    }
}