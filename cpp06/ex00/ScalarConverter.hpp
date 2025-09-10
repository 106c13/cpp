#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "string"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& src);

	static void	print(char value);
	static void	print(long value);
	static void	print(double value);
	static void	print(float value);
public:
	static void	convert(const std::string& literal);

};

/* checker.cpp */
size_t	skipDigit(const std::string& literal, size_t i, char delim);
bool	isChar(const std::string& literal);
bool	isInt(const std::string& literal);
bool	isDouble(const std::string& literal);
bool	isFloat(const std::string& literal);

#endif
