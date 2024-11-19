#include "BitcoinExchange.hpp"

void stockDatafile(std::map<std::string, float>& exchangeRates)
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open the file data.csv" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream lineStream(line);
        std::string date;
        std::string rateStr;
        if (std::getline(lineStream, date, ','))
        {
            lineStream >> rateStr;
            float rate;
            std::istringstream(rateStr) >> rate;
            exchangeRates[date] = rate;
            
        }
    }
    file.close();
}

void ft_convert(const std::string& filename, const std::map<std::string, float>& datafile)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    std::string date;
    std::string valueStr;

    while (std::getline(file, line))
    {
        if (parseInputLine(line) == 1)
            continue;
        date = line.substr(0, 10);
        valueStr = line.substr(13);
        float value = std::atof(valueStr.c_str());
        float rate = getExchangeRate(date, datafile);
        if (rate == -1)
            continue;
        float result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}

float getExchangeRate(const std::string& date, const std::map<std::string, float>& datafile)
{
    std::map<std::string, float>::const_iterator it = datafile.lower_bound(date);

    if (it == datafile.begin() && it->first != date)
    {
        std::cerr << "Error: No earlier date found for " << date << std::endl;
        return (-1);
    }
    if (it == datafile.end() || it->first != date)
        --it;
    return (it->second);  
}

int parseInputLine(std::string line)
{
    if (line == "date | value")
        return(1);
    if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
    {
          std::cerr << "Error: bad input => " << line << std::endl;
        return (1);
    }
    std::string date = line.substr(0, 10);
    std::string valueStr = line.substr(13);
    if (parseDate(date) != 0)
    {
       std::cerr << "Error: bad input => " << date << std::endl;
        return (1);
    }
    if (parseValue(valueStr) != 0)
    {
        return (1);
    }
    return (0);
}

int parseDate(const std::string& date)
{
    int month;
    int day;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (1);
    month = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));

    if ((month < 1 || month > 12) || (day < 1 || day > 31))
        return (1);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return (1);
    if (month == 2 && day > 28)
        return (1);
    return (0);
}

int parseValue(const std::string& valueStr)
{
    int dot = 0;

    if (valueStr[0] == '-')
    {
        std::cerr << "Error: not a positive number => " << valueStr << std::endl;
        return (1);
    }
    for (size_t i = 0; i < valueStr.size(); ++i)
    {
        if (valueStr[i] == '.')
        {
            if (dot == 1)
            {
                std::cerr << "Error: Value can contain only digit. => " << valueStr << std::endl;
                return (1);
            }  
            dot = 1;
        }
        else if (!isdigit(valueStr[i]))
        {
             std::cerr << "Error: Value can contain only digit. => " << valueStr << std::endl;
             return (1);
        }  
    }

    float value = std::atof(valueStr.c_str());

    if (value > 1000)
    {
        std::cerr << "Error: too large number  => " << valueStr << std::endl;
        return (1);
    }
    return (0);
}