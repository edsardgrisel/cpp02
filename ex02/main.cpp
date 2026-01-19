#include <iostream>
#include "Fixed.hpp"

std::string	getTrueOrFalse(int num)
{
	return (num == 1) ? "true" : "false";
}

int main( void ) {
	Fixed a(5.0f);
	Fixed b(3.0f);
	Fixed c(2);

	// Comparison operator overloading tests
	std::cout << "\nComparison Tests" << std::endl;
	std::cout << "a(5.0) > b(3.0): " << getTrueOrFalse(a > b) << std::endl;
	std::cout << "a(5.0) < b(3.0): " << getTrueOrFalse(a < b) << std::endl;
	std::cout << "a(5.0) >= b(3.0): " << getTrueOrFalse(a >= b) << std::endl;
	std::cout << "b(3.0) <= a(5.0): " << getTrueOrFalse(b <= a) << std::endl;
	std::cout << "a(5.0) == c(2): " << getTrueOrFalse(a == c) << std::endl;
	std::cout << "a(5.0) != b(3.0): " << getTrueOrFalse(a != b) << std::endl;


	// Arithmetic operator overloading tests
	std::cout << "\nArithmetic Tests" << std::endl;
	std::cout << "a(5.0) + b(3.0) = " << (a + b) << std::endl;
	std::cout << "a(5.0) - b(3.0) = " << (a - b) << std::endl;
	std::cout << "a(5.0) * b(3.0) = " << (a * b) << std::endl;
	std::cout << "a(5.0) / c(2) = " << (a / c) << std::endl;

	// Incrementing and decrementing tests
	Fixed d(0);
	std::cout << "\nIncrementing and decrementing tests" << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "++d = " << ++d << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;

	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "--d = " << --d << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;

	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "d++ = " << d++ << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;

	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "d-- = " << d-- << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;

	// Min max tests
	std::cout << "\nMin max tests" << std::endl;
	std::cout << "min a(5.0) and b(3.0): " << Fixed::min(a, b) << std::endl;
	std::cout << "max a(5.0) and b(3.0): " << Fixed::max(a, b) << std::endl;
	const Fixed e(5.0f);
	const Fixed f(3.0f);
	std::cout << "const min a(5.0) and b(3.0): " << Fixed::min(e, f) << std::endl;
	std::cout << "const max a(5.0) and b(3.0): " << Fixed::max(e, f) << std::endl;

}










// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }