#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->value = static_cast<int>(roundf(value * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
}

// EX02 operator overloads
// Comparison operators
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->value > other.value);
}
bool	Fixed::operator<(const Fixed &other) const
{
	return (this->value < other.value);
}
bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->value >= other.value);

}
bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->value <= other.value);

}
bool	Fixed::operator==(const Fixed &other) const
{
	return (this->value == other.value);
}
bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->value != other.value);
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed fixed;
	fixed.value = this->value + other.value;
	return fixed;
}
Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed fixed;
	fixed.value = this->value - other.value;
	return fixed;
}
Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed fixed;
	fixed.value = (this->value * other.value) >> this->fractionalBits;
	return fixed;
}
Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed fixed;
	fixed.value = (this->value << this->fractionalBits) / other.value;
	return fixed;
}

// Increment and decrement
Fixed&	Fixed::operator++()// Pre increment
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)// Post increment
{
	Fixed	temp(*this);
	this->value++;
	return (temp);
}

Fixed&	Fixed::operator--()// Pre decrement
{
	this->value--;
	return (*this);
}
Fixed	Fixed::operator--(int)// Post decrement
{
	Fixed	temp(*this);
	this->value--;
	return (temp);
}

// Public overloaded member functions
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
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

