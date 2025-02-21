/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/21 02:21:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* constructor ---------------------------------------------------------------*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << CYAN "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	std::cout << CYAN "Copy constructor called" RESET << std::endl;
	*this = toCopy;
}

Fixed::Fixed(const int toCopy)
{
	std::cout << CYAN "Int constructor called" RESET << std::endl;
	this->_value = toCopy << this->_precisionInBit;
	// this->setRawBits(toCopy << _precisionInBit);
}

Fixed::Fixed(const float toCopy)
{
	std::cout << CYAN "Float constructor called" RESET << std::endl;
	*this = toCopy;
}

/* operator ------------------------------------------------------------------*/

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	std::cout << PURPLE "Copy assignment operator called" RESET << std::endl;
	if (this != &toCopy)
		this->_value = toCopy.getRawBits();
	return (*this);
}

/* destructor ----------------------------------------------------------------*/

Fixed::~Fixed(void)
{
	std::cout << BLUE "Destructor called" RESET << std::endl;
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
	float result = this->_value / 256;

	return (result);
}
int Fixed::toInt(void) const
{
	
	float result = this->_value >> 8;

	return (result);
}
