#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static const int	_fractValue;
public:
	Fixed();
	Fixed( const Fixed& src );
	Fixed &operator=( const Fixed& src );
	~Fixed();
	
	void	getRawBits( void ) const;
	void	setRawBits( int const raw );
}
