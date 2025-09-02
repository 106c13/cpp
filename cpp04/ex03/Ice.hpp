#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& src);
	virtual ~Ice();

	Ice&	operator=(const Ice& src);

	AMateria*   clone() const;
	void        use(ICharacter& target);
};

#endif

