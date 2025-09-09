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

	void	print_char(int value);
	void	print_int(int value);
	void	print_float(int value);
	void	print_double(int value);
public:
	static void	convert(std::string& literal);

};




#endif
