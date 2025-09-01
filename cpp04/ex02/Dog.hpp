#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
private:
	Brain*	_brain;
public:
	Dog();
	Dog(const Dog& src);
	~Dog();

	Dog&	operator=(const Dog& src);

	void		makeSound() const;
	void		setBrainIdea(int i, const std::string& str);
	std::string	getBrainIdea(int i) const;

};

#endif
