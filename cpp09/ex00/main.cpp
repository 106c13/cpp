#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc("data.csv");

		std::ifstream input(argv[1]);
		if (!input.is_open())
			throw BitcoinExchange::CouldNotOpenFile();

		std::string line;
		std::getline(input, line);
		while (std::getline(input, line))
		{
			std::stringstream ss(line);
			std::string date, valueStr;
			if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			date.erase(0, date.find_first_not_of(" \t"));
			date.erase(date.find_last_not_of(" \t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \t"));
			valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

			if (date.empty() || valueStr.empty()) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			float value = std::atof(valueStr.c_str());
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			try {
				float result = btc.toDollar(date, value);
				std::cout << date << " => " << value << " = " << result << std::endl;
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		input.close();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
