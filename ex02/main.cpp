/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:46:03 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/22 20:34:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <bitset>
#include "Fixed.hpp"

void displayBool(std::string const & str, bool value)
{
	std::cout << YELLOW << str << " = " RESET << std::boolalpha << value << std::endl;
}

void	displayFixed(std::string const & str, Fixed const & fixed)
{
	int raw = fixed.getRawBits();
	std::cout << YELLOW << str << " = " RESET << std::setw(20) << std::setprecision(20) << fixed;
	std::cout << YELLOW " in binary : " RESET << std::bitset<24>(raw >> 8) << " " << std::bitset<8>(raw) << std::endl;
} 

void test(Fixed const & a, Fixed const & c)
{
	displayFixed("a", a);
	displayFixed("c", c);
	
	std::cout << std::endl;
	
	displayBool("a < c", a < c);
	displayBool("a > c", a > c);
	displayBool("a <= c", a <= c);
	displayBool("a >= c", a >= c);
	displayBool("a == c", a == c);
	displayBool("a != c", a != c);

	std::cout << std::endl;

	displayBool("a < a", a < a);
	displayBool("a > a", a > a);
	displayBool("a <= a", a <= a);
	displayBool("a >= a", a >= a);
	displayBool("a == a", a == a);
	displayBool("a != a", a != a);

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("a", a);
	displayFixed("c", c);
	
	std::cout << std::endl;
	
	displayFixed("a + c", a + c);
	displayFixed("a - c", a - c);
	displayFixed("a * c", a * c);
	displayFixed("a / c", a / c);

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("a", a);
	displayFixed("c", c);
	
	std::cout << std::endl;
	
	displayFixed("a + a", a + a);
	displayFixed("a - a", a - a);
	displayFixed("a * a", a * a);
	displayFixed("a / a", a / a);

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("a", a);
	displayFixed("c", c);
	
	std::cout << std::endl;
	
	displayFixed("c + c", c + c);
	displayFixed("c - c", c - c);
	displayFixed("c * c", c * c);
	displayFixed("c / c", c / c);

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("a", a);
	displayFixed("c", c);
	
	std::cout << std::endl;
	
	displayFixed("min(a, c)", Fixed::min(a, c));
	displayFixed("min(c, a)", Fixed::min(c, a));
	displayFixed("min(a, a)", Fixed::min(a, a));
	displayFixed("min(c, c)", Fixed::min(c, c));

	std::cout << std::endl;
	
	displayFixed("max(a, c)", Fixed::max(a, c));
	displayFixed("max(c, a)", Fixed::max(c, a));
	displayFixed("max(a, a)", Fixed::max(a, a));
	displayFixed("max(c, c)", Fixed::max(c, c));
	
	std::cout << "***********************************************" << std::endl;
}

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed(5.05f) * Fixed(2) );
	Fixed		c = Fixed(5.05f);
	
	std::cout << "-----------------------------------------------" << std::endl;
	displayFixed("a", a);
	displayFixed("b", b);
	displayFixed("c", c);

	std::cout << "-----------------------------------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-----------------------------------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "-----------------------------------------------" << std::endl;
	
	c = Fixed(10);

	std::cout << "***********************************************" << std::endl;
	
	++a;
	test(a, c);
	
	std::cout << "***********************************************" << std::endl;

	c = Fixed(-10);
	test(a, c);

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("a", a);
	displayFixed("a / 0", a / Fixed());

	std::cout << "-----------------------------------------------" << std::endl;
	
	displayFixed("c", c);
	displayFixed("c / 0", c / Fixed());

	std::cout << "-----------------------------"  << std::endl << std::endl;
	
	a = Fixed(300000);
	displayFixed("300000++", ++a);
	// int raw = a.getRawBits();
	// std::cout << "300000 = " << std::setprecision(20) << result << " in binary : " << std::bitset<24>(raw >> 8) << " " << std::bitset<8>(raw) << std::endl;

	std::cout << std::endl << "-----------------------------" << std::endl;

	return 0;
}
