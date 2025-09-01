#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
private:
	Brain*	_brain;
public:
	Cat();
	Cat(const Cat& src);
	~Cat();

	Cat&	operator=(const Cat& src);

	void		makeSound() const;
	void		setBrainIdea(int i, const std::string& str);
	std::string	getBrainIdea(int i) const;
};

#endif
