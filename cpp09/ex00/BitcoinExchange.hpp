#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib> 

void stockDatafile(std::map<std::string, float>& exchangeRates);
int parseDate(const std::string& date);
void ft_convert(const std::string& filename, const std::map<std::string, float>& datafile);
int parseValue(const std::string& valueStr);
float getExchangeRate(const std::string& date, const std::map<std::string, float>& datafile);
int parseInputLine(std::string line);

#endif