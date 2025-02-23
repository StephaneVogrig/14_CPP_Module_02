/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/23 14:19:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits.h>
#include <bitset>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define GREY "\033[37m"
# define RESET "\033[0m"

/*
	value in deciaml for each bit after point.
	10000000 = 0.5
	01000000 = 0.25
	00100000 = 0.125
	00010000 = 0.0625
	00001000 = 0.03125
	00000100 = 0.015625
	00000010 = 0.0078125
	00000001 = 0.00390625
*/

class Fixed
{
	public:

		Fixed(void);
		Fixed(Fixed const & toCopy);
		Fixed(int const intValue);
		Fixed(float const floatValue);

		~Fixed(void);

		Fixed & operator = (Fixed const & toAssign);

		bool operator >  (Fixed const & rhs) const;
		bool operator <  (Fixed const & rhs) const;
		bool operator >= (Fixed const & rhs) const;
		bool operator <= (Fixed const & rhs) const;
		bool operator == (Fixed const & rhs) const;
		bool operator != (Fixed const & rhs) const;

		Fixed operator + (Fixed const & rhs) const;
		Fixed operator - (Fixed const & rhs) const;
		Fixed operator * (Fixed const & rhs) const;
		Fixed operator / (Fixed const & rhs) const;

		Fixed &	operator ++ (void);
		Fixed &	operator -- (void);
		Fixed	operator ++ (int);
		Fixed	operator -- (int);

		static Fixed &			min(Fixed & a, Fixed & b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed &			max(Fixed & a, Fixed & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);

		int			getRawBits(void) const;
		static int	getPrecisionBits(void);
		void		setRawBits(int const raw);

		float	toFloat(void) const;
		double	toDouble(void) const;
		int		toInt(void) const;

	private:

		int					_value;
		static int const	_precisionInBit;

};

std::ostream& operator << (std::ostream& os, const Fixed& obj);

#endif
