#include <iostream>
#include <string>
#include <cctype>
#include "BitcoinExchange.hpp"

static bool	checkDate(const std::string& date)
{
	if (date.size() != 10 || (date[4] != '-' || date[7] != '-'))
	   return false;
	for (int i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(
	}	
}


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	db_ = src.db_;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		db_ = src.db_;

	return *this;
}

float	toDollar(const std::string& date, float value) const {
	//check the value
	//find closest date
	//multiple by exchange value
	//return
}
