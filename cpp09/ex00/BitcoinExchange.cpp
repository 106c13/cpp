#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iomanip>


// ===== Constructors =====
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
	loadDB(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src)
		db_ = src.db_;
	return *this;
}

// ===== Helper functions =====
static bool isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y, m, d;
	if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
		return false;
	if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	// Basic day check
	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	if (leap) daysInMonth[1] = 29;
	if (d > daysInMonth[m - 1]) return false;

	return true;
}

// ===== Load CSV Database =====
void BitcoinExchange::loadDB(const std::string& dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw CouldNotOpenFile();

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, priceStr;
		if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr))
			continue;

		float price = std::strtof(priceStr.c_str(), NULL);
		if (isValidDate(date))
			db_[date] = price;
	}
	file.close();
}

// ===== Get Closest Date (lower bound) =====
static std::string getClosestDate(const std::map<std::string, float>& db, const std::string& date)
{
	if (db.empty()) return "";

	std::map<std::string, float>::const_iterator it = db.lower_bound(date);
	if (it == db.begin())
		return it->first;
	if (it == db.end() || it->first != date)
		--it;
	return it->first;
}

// ===== Compute value =====
float BitcoinExchange::toDollar(const std::string& date, float value) const
{
	if (db_.size() == 0)
		throw EmptyDataBase();
	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << date;
		throw InvalidDateFormat();
	}

	std::string closest = getClosestDate(db_, date);
	std::map<std::string, float>::const_iterator it = db_.find(closest);
	if (it == db_.end())
		return 0.0f;

	return value * it->second;
}

// ===== Exceptions =====
const char*	BitcoinExchange::EmptyDataBase::what() const throw() {
	return "DB is empty";
}

const char* BitcoinExchange::InvalidDateFormat::what() const throw() {
	return "";
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw() {
	return "Error: could not open file.";
}
