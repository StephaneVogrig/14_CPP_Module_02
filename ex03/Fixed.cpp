/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 14:12:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_precisionInBit = 8;

/* constructor ---------------------------------------------------------------*/

Fixed::Fixed(void) : _value(0)
{}

Fixed::Fixed(Fixed const & toCopy)
{
	*this = toCopy;
}

Fixed::Fixed(int const intValue)
{
	_value = intValue << _precisionInBit;
}

Fixed::Fixed(float const floatValue)
{
	_value = (int)roundf(floatValue * (1 << _precisionInBit));
}

/* destructor ----------------------------------------------------------------*/

Fixed::~Fixed(void)
{}


/* operator ------------------------------------------------------------------*/

Fixed & Fixed::operator = (Fixed const & toAssign)
{
	if (this != &toAssign)
		_value = toAssign._value;
	return (*this);
}

std::ostream & operator << (std::ostream & os, Fixed const & fixed)
{
	os << fixed.toDouble();
	return (os);
}

bool Fixed::operator > (Fixed const & rhs) const
{
	return (_value > rhs._value);
}

bool Fixed::operator < (Fixed const & rhs) const
{
	return (_value < rhs._value);
}

bool Fixed::operator >= (Fixed const & rhs) const
{
	return (_value >= rhs._value);
}

bool Fixed::operator <= (Fixed const & rhs) const
{
	return (_value <= rhs._value);
}

bool Fixed::operator == (Fixed const & rhs) const
{
	return (_value == rhs._value);
}

bool Fixed::operator != (Fixed const & rhs) const
{
	return (_value != rhs._value);
}

Fixed Fixed::operator + (Fixed const & rhs) const
{
	Fixed result;
	result._value = _value + rhs._value;
	return (result);
}

Fixed Fixed::operator - (Fixed const & rhs) const
{
	Fixed result;
	result._value = _value - rhs._value;
	return (result);
}

Fixed Fixed::operator * (Fixed const & rhs) const
{
	return (Fixed((float)(toDouble() * rhs.toDouble())));
}

Fixed Fixed::operator / (Fixed const & rhs) const
{
	if (rhs._value == 0)
	{
		std::cout << RED "Divide by zero !" RESET << std::endl;
		Fixed result;
		if (*this < result)
			result.setRawBits(INT_MIN);
		else
			result.setRawBits(INT_MAX);
		return (result);
	}
	return (Fixed((float)(toDouble() / rhs.toDouble())));
}

Fixed& Fixed::operator ++ (void)
{
	_value++;
	return (*this);
}

Fixed& Fixed::operator -- (void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed old = *this;
	operator++();
	return (old);
}

Fixed Fixed::operator-- (int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

/* min max -------------------------------------------------------------------*/

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return (a._value < b._value ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a._value < b._value ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return (a._value > b._value ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a._value > b._value ? a : b);
}

/* getter setter -------------------------------------------------------------*/

int Fixed::getRawBits(void) const
{
	return (_value);
}

int		Fixed::getPrecisionBits(void)
{
	return (_precisionInBit);
}

void Fixed::setRawBits(int const intValue)
{
	_value = intValue;
}

/* convert -------------------------------------------------------------------*/

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _precisionInBit));
}

double Fixed::toDouble(void) const
{
	return ((double)_value / (1 << _precisionInBit));
}

int Fixed::toInt(void) const
{
	return ((int)roundf(toFloat()));
}
