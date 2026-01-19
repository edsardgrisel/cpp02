#include <iostream>

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

	// EX02 operator overloads
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	Fixed	&operator++(); // Pre increment
	Fixed	operator++(int); // Post increment
	Fixed	&operator--(); // Pre decrement
	Fixed	operator--(int); // Post decrement

	// EX02 overloaded member functions
	static	Fixed&			min(Fixed& a, Fixed& b);
	static	const Fixed&	min(const Fixed& a, const Fixed& b);
	static	Fixed&			max(Fixed& a, Fixed& b);
	static	const Fixed&	max(const Fixed& a, const Fixed& b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& fixed);