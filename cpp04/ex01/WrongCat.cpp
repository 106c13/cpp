#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "🐱 WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "🐱 WrongCat copy constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	std::cout << "🐱 WrongCat copy operator called\n";
	if (this != &src)
		type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "🐱 WrongCat desctructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "🐱 WrongCat: meow\n";
}
