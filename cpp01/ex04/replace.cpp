#include <iostream>
#include <string>
#include <fstream>
#include "replace.hpp"

std::string	replace(std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	newLine;
	size_t		pos;
	size_t		prev = 0;

	while (true)
	{
		pos = line.find(s1, prev);
		if (pos == std::string::npos)
		{
			newLine += line.substr(prev);
			break ;
		}
		newLine += line.substr(prev, pos - prev);
		newLine += s2;
		prev = pos + s1.length();
	}
	return (newLine);
}


void	replaceFileContent(const char* fileName, const std::string& s1, const std::string& s2)
{
	std::ofstream	fileReplace;
	std::ifstream	file;
	std::string		line;
	std::string		newFileName;

	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "Can't open the file\n";
		return ;
	}
	newFileName = std::string(fileName) + ".replace";
	fileReplace.open(newFileName.c_str());
	if (!fileReplace.is_open())
	{
		std::cout << "Can't create replace file\n";
		file.close();
		return ;
	}
	while (getline(file, line))
	{
		fileReplace << replace(line, s1, s2) << std::endl;
	}
	file.close();
	fileReplace.close();
}
