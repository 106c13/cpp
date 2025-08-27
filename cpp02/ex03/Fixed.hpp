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

	bool			operator>( const Fixed& src ) const;
	bool			operator<( const Fixed& src ) const;
	bool			operator>=( const Fixed& src ) const;
	bool			operator<=( const Fixed& src ) const;
	bool			operator==( const Fixed& src ) const;
	bool			operator!=( const Fixed& src ) const;
	Fixed			operator+( const Fixed& src ) const;
	Fixed			operator-( const Fixed& src ) const;
	Fixed			operator*( const Fixed& src ) const;
	Fixed			operator/( const Fixed& src ) const;
	Fixed			operator++();
	Fixed			operator--();
	Fixed			operator++( int );
	Fixed			operator--( int );
	static Fixed&	min( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static Fixed&	max( Fixed& a, Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<( std::ostream& o, const Fixed& fixed );

#endif
