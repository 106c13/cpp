#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class	AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal& src);
	virtual ~AAnimal();

	AAnimal&			operator=(const AAnimal& src);
	virtual void		makeSound() const = 0;
	std::string			getType() const;
};
#endif
