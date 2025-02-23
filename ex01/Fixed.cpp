/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 16:32:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* constructor ---------------------------------------------------------------*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << CYAN "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(Fixed const & toCopy)
{
	std::cout << CYAN "Copy constructor called" RESET << std::endl;
	*this = toCopy;
}

Fixed::Fixed(int const intValue)
{
	std::cout << CYAN "Int constructor called" RESET << std::endl;
	this->_value = intValue << _precisionInBit;
}

Fixed::Fixed(float const floatValue)
{
	std::cout << CYAN "Float constructor called" RESET << std::endl;
	this->_value = (int)roundf(floatValue * (1 << _precisionInBit));
}

/* destructor ----------------------------------------------------------------*/

Fixed::~Fixed(void)
{
	std::cout << BLUE "Destructor called" RESET << std::endl;
}

/* operator ------------------------------------------------------------------*/

Fixed & Fixed::operator = (Fixed const & toAssign)
{
	std::cout << PURPLE "Copy assignment operator called" RESET << std::endl;
	if (this == &toAssign)
		return (*this);
	_value = toAssign._value;
	return (*this);
}

std::ostream & operator << (std::ostream & os, Fixed const & obj)
{
	os << obj.toFloat();
	return (os);
}

/* getter setter -------------------------------------------------------------*/

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

/* convert -------------------------------------------------------------------*/

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _precisionInBit));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _precisionInBit);
}
