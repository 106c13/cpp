#include <string>

size_t	skipDigit(const std::string& literal, size_t i, char delim)
{
	for (; i < literal.size(); i++)
	{
		if (literal[i] == delim)
			break ;
		if (!isdigit(literal[i]))
			return (std::string::npos);
	}
	return (i);
}

bool	isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (literal[i] == '\0')
		return (false);
	i = skipDigit(literal, i, 0);
	return (i != std::string::npos);
}

bool	isDouble(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (!isdigit(literal[i]))
		return (false);
	i = skipDigit(literal, i, '.');
	if (i == std::string::npos)
		return (false);
	i++;
	if (!isdigit(literal[i]))
		return (false);
	i = skipDigit(literal, i, 0);
	return (i != std::string::npos);
}

bool	isFloat(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (!isdigit(literal[i]))
		return (false);
	i = skipDigit(literal, i, '.');
	if (i == std::string::npos)
		return (false);
	i++;
	if (!isdigit(literal[i]))
		return (false);
	i = skipDigit(literal, i, 'f');
	if (literal[i++] != 'f')
		return (false);
	return (i != std::string::npos && i == literal.size());
}
