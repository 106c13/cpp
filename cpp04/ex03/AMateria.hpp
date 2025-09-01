#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class	AMateria
{
protected:
public:
	AMateria();
	AMateria(const AMateria& src);
	AMateria(std::string const & type);
	~AMateria();

	AMateria&	operator=(const AMateria& src);

	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
