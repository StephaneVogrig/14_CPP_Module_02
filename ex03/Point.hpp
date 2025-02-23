/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:43:35 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 00:04:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:

		Point(void);
		Point(float const x, float const y);
		Point(Point const & toCopy);
		Point & operator = (Point const & toAssign);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:

		Fixed const _x;
		Fixed const _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif