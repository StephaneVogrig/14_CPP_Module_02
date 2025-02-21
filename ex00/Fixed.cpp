/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/21 01:41:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << CYAN "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << CYAN "Copy constructor called" RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << PURPLE "Copy assignment operator called" RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BLUE "Destructor called" RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member functio called" RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << GREY "setRawBits member functio called" RESET << std::endl;
	this->_value = raw;
}
