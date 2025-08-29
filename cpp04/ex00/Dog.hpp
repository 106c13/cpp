#ifndef DOG_HPP
# define DOG_HPP

class	Dog
{
public:
	Dog();
	Dog(const Dog& src);
	Dog		operator=(const Dog& src);
	~Dog();
	void	makeSound();
};

#endif
