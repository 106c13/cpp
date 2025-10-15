#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, float> db_;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange(const std::string& dbFile);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& src);

	float toDollar(const std::string& date, float value) const;
	void loadDB(const std::string& dbFile);

	class EmptyDataBase: public std::exception {
		public:
			const char*	what() const throw();
	};

	class InvalidDateFormat : public std::exception {
	public:
		const char* what() const throw();
	};

	class CouldNotOpenFile : public std::exception {
	public:
		const char* what() const throw();
	};
};

#endif
