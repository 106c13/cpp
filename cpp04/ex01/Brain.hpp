#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain& src);
	~Brain();

	Brain&		operator=(const Brain& src);

	std::string	getIdea(int i) const;
	void		setIdea(int i, const std::string& string);
};

#endif
