/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:54:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 01:30:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed determinant(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed det = determinant(point, a, b);
	if (det == 0)
		return (false);
	bool sign = det > 0;
	det = determinant(point, b, c);
	if (det == 0 || sign != (det > 0))
		return (false);
	det = determinant(point, c, a);
	if (det == 0 || sign != (det > 0))
		return (false);
	return (true);
}
