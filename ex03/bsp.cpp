/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:54:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 13:47:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	How to determine if a point is in a 2D triangle?

	This routine works by taking each line in the triangle and determining which
	side of the line the point is on.
	This is done using the "determinant" of the three points.
	The side is indicate by the sign of the determinant.
	If determinant is zero, the point is on the line.
	If a point is on the same side (same determinant sign) of all sides in the triangle,
	the point is inside the triangle.
	Conversely, if a point isn't on the same side, it is out of side the triangle.
	This applies no matter the order in which the line are presented,
	as long as the points are traversed in order.

	https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

	More methode and accuracy problems:
	https://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html

	Implemantation in many langages:
	https://rosettacode.org/wiki/Find_if_a_point_is_within_a_triangle#C

*/

Fixed determinant(Point const p1, Point const p2, Point const p3)
{
	return ( (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()) );
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
