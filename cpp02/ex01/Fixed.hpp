#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed
{
private:
	int					_value;
	static const int	_fract_bits;
public:
	Fixed();
	Fixed( const float n );
	Fixed( const int n );
	Fixed( const Fixed& src );
	Fixed& operator=( const Fixed& src );
	~Fixed();
	
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<( std::ostream& o, const Fixed& fixed );

#endif
