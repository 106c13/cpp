#include <limits>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return (*this);
}

/* For CHAR */
void	ScalarConverter::print(char value)
{
	std::cout << "Char: '" <<  static_cast<char>(value) << '\'' << std::endl;
	std::cout << "Int: " <<  static_cast<int>(value) << std::endl;
	std::cout << "Double: " << static_cast<double>(value) << ".0" << std::endl;
	std::cout << "Float: " <<  static_cast<float>(value) << ".0f" << std::endl;
}

/* For INT */
void	ScalarConverter::print(long value)
{
	if (value < 0 || value > 255)
		std::cout << "Char: Out of range\n";
	else if (value < 32 || value > 126)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: '" <<  static_cast<char>(value) << '\'' << std::endl;
	
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Int: Out of range\n";
	else
		std::cout << "Int: " <<  static_cast<int>(value) << std::endl;

	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		std::cout << "Double: Out of range\n";
	else
		std::cout << "Double: " <<  static_cast<double>(value) << ".0" << std::endl;

	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "Float: Out of range\n";
	else
		std::cout << "Float: " <<  static_cast<float>(value) << ".0f" << std::endl;
}

/* For DOUBLE */
void	ScalarConverter::print(double value)
{
	bool	hasFract = false;

	if (value != static_cast<long>(value))
		hasFract = true;

	if (value < 0 || value > 255)
		std::cout << "Char: Out of range\n";
	else if (value < 32 || value > 126)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: '" <<  static_cast<char>(value) << '\'' << std::endl;

	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Int: Out of range\n";
	else
		std::cout << "Int: " <<  static_cast<int>(value) << std::endl;

	std::cout << "Double: " << value;
	if (!hasFract)
		std::cout << ".0";
	std::cout << std::endl;
	
	std::cout << "Float: " <<  static_cast<float>(value);
	if (!hasFract)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

/* For FLOAT */
void	ScalarConverter::print(float value)
{
	long	tmp = static_cast<long>(value);
	bool	hasFract = false;

	if (value != tmp)
		hasFract = true;

	if (tmp < 0 || tmp > 255)
		std::cout << "Char: Out of range\n";
	else if (tmp < 32 || tmp > 126)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: '" <<  static_cast<char>(value) << '\'' << std::endl;

	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "Int: Out of range\n";
	else
		std::cout << "Int: " <<  static_cast<int>(value) << std::endl;

	std::cout << "Double: " <<  static_cast<double>(value);
	if (!hasFract)
		std::cout << ".0";
	std::cout << std::endl;

	std::cout << "Float: " <<  static_cast<float>(value);
	if (!hasFract)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	ScalarConverter::convert(const std::string& literal)
{
	long		intValue;
	char		charValue;
	double		doubleValue;
	float		floatValue;

	errno = 0;
	if (literal == "nan")
	{
		std::cout << "Char: impossible\n";
		std::cout << "Int: impossible\n";
		std::cout << "Double: nan\n";
		std::cout << "Float: nanf\n";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "Char: impossible\n";
		std::cout << "Int: impossible\n";
		std::cout << "Double: -inf\n";
		std::cout << "Float: -inff\n";
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "Char: impossible\n";
		std::cout << "Int: impossible\n";
		std::cout << "Double: +inf\n";
		std::cout << "Float: +inff\n";
	}
	else if (isChar(literal))
	{
		charValue = literal[0];
		print(charValue);
	}
	else if (isInt(literal))
	{
		intValue = std::strtol(literal.c_str(), NULL, 10);
		if (errno == ERANGE)
		{
			std::cout << "Char: Out of range\n";
			std::cout << "Int: Out of range\n";
			doubleValue = std::strtod(literal.c_str(), NULL);
			std::cout << "Double: " << doubleValue << std::endl;
			std::cout << "Float: " << static_cast<float>(doubleValue) << 'f' << std::endl;
			return ;
		}
		print(intValue);
	}
	else if (isDouble(literal))
	{
		doubleValue = std::strtod(literal.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "Char: Out of range\n";
			std::cout << "Int: Out of range\n";
			std::cout << "Double: " << doubleValue << std::endl;
			std::cout << "Float: " << static_cast<float>(doubleValue) << 'f' << std::endl;
			return ;
		}
		print(doubleValue);
	}
	else if (isFloat(literal))
	{
		floatValue = static_cast<float>(std::strtod(literal.c_str(), NULL));
		if (errno == ERANGE)
		{
			std::cout << "Char: Out of range\n";
			std::cout << "Int: Out of range\n";
			std::cout << "Double: " << static_cast<double>(floatValue) << std::endl;
			std::cout << "Float: " << floatValue << 'f' << std::endl;
			return ;
		}
		print(floatValue);
	}
	else
		std::cout << "Invalid input\n";
}
