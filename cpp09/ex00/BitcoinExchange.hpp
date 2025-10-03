#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <exception>

class BitcoinExchange
{
private:
	std::map<int>	db_;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& src);

	float	toDollar(const std::string& date, float value) const;

	class	InvalidDateFormat: public std::exception {
		public: const char*	what() const throw();
	}

	class	CouldNotOpenFile: public std::exception {
		public: const char*	what() const throw();
	}
};
#endif
