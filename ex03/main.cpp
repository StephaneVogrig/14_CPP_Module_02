/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:46:03 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 15:04:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(-1.0f, -9.0f);
	Point b(35.0f, 0.0f);
	Point c(-1.0f, 9.0f);

	Fixed x_min = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX())) - 5;
	Fixed x_max = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX())) + 5;
	Fixed y_min = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY())) - 1;
	Fixed y_max = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY())) + 2;

	for (Fixed y = y_min; y < y_max; y = y + 1.0f)
	{
		std::cout << "    ";
		for (Fixed x = x_min; x < x_max; x = x + 1.0f)
		{
			std::cout << (bsp(a, b, c, Point(x.toFloat(), y.toFloat())) ?  RESET : RED) << "█";
		}
		std::cout << RESET << std::endl;
	}

	return 0;
}
