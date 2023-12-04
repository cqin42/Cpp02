/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:05:30 by christine         #+#    #+#             */
/*   Updated: 2023/12/04 19:55:23 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &autre);
		Fixed& operator=(const Fixed &autre);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		static const int _rawBits;
		int	_fixedNb;
};

std::ostream & operator<<(std::ostream & o, Fixed const &nb);

#endif
