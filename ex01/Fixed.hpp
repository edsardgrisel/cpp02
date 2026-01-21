#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
private:
	int					value;
	static const int	fractionalBits = 8;
public:
	// Default and parameterized constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	// Copy constructor
	Fixed(const Fixed &other);
	// Copy assignment operator overload
	Fixed	&operator=(const Fixed &other);
	// Destructor
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& fixed);

#endif // FIXED_HPP
