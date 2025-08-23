#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
		_name = name;
	}
};

#endif
