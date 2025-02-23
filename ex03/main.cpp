/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:46:03 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 01:31:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(-0.0f, -1.0f);
	Point b(-0.0f, 1.1f);
	Point c(4.0f, 0.0f);
	Point point(0.5f, 0.5f);

	Fixed x_min = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX())) - 1;
	Fixed x_max = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX())) + 1;
	Fixed y_min = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY())) - 1;
	Fixed y_max = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY())) + 1;

	for (Fixed y = y_min; y < y_max; y = y + 0.1f)
	{
		for (Fixed x = x_min; x < x_max; x = x + 0.1f)
		{
			std::cout << (bsp(a, b, c, Point(x.toFloat(), y.toFloat())) ?  RESET : RED) << "█";
		}
		std::cout << RESET << std::endl;
	}

	return 0;
}
