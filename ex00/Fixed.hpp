/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:41:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/21 14:03:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define GREY "\033[37m"
# define RESET "\033[0m"

class Fixed
{
	public:
	
		Fixed(void);
		Fixed(Fixed const & toCopy);
		Fixed& operator=(Fixed const & toAssign);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const intValue);

	private:

		int					_value;
		static const int	_precisionInBit = 8;

};

#endif
