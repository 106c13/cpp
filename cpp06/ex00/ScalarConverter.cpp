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
	*this = src;
	return (*this);
}

void	ScalarConverter::print_char(int value)
{
	if (value < 32 || value > 128)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: " <<  static_cast<char>(value) << std::endl;
}
void	ScalarConverter::convert(const std::string& literal)
{
	int		intValue;
	double	doubleValue;
	float	floatValue;

	if (isInt(literal))
	{
		try
		{
			intValue = std::stoi(literal);
			print_char(intValue);
			std::cout << "Int: " << intValue << std::endl;
		}
		catch (std::out_of_range& e)
		{
			std::cout << "Int: Out of range\n";
		}
	}
	else if (isDouble(literal))
	{
		try {
			doubleValue = std::stod(literal);
			std::cout << "Double: " << doubleValue << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Double: Out of range\n";
		}
	}
	else if (isFloat(literal))
	{
		try
		{
			floatValue = std::stof(literal);
			std::cout << "Float: " << floatValue << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Float: Out of range\n";
		}
	}
	else
		std::cout << "Invalid input\n";
}
