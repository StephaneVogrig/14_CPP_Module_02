/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:43:28 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 01:29:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(float const x, float const y) : _x(x), _y(y)
{}

Point::Point(Point const & toCopy) : _x(toCopy._x), _y(toCopy._y)
{}

Point & Point::operator = (Point const &)
{
	return (*this);
}

Point::~Point(void)
{}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}
