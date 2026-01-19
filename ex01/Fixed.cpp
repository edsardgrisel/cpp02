#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->value = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->value = static_cast<int>(roundf(value * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits() const
{
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << this->fractionalBits);
}

int		Fixed::toInt( void ) const
{
	return this->value >> this->fractionalBits;
}

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

