/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 16:33:56 by svogrig          ###   ########.fr       */
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
	_value = toAssign.getRawBits();
	return (*this);
}

/* getter setter -------------------------------------------------------------*/

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called" RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << GREY "setRawBits member function called" RESET << std::endl;
	this->_value = raw;
}
