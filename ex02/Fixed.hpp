/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:05:30 by christine         #+#    #+#             */
/*   Updated: 2023/12/04 22:28:37 by christine        ###   ########.fr       */
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
		~Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &autre);
		Fixed& operator=(const Fixed &autre);

		bool operator>(const Fixed &autre) const;
		bool operator<(const Fixed &autre) const;
		bool operator>=(const Fixed &autre) const;
		bool operator<=(const Fixed &autre) const;
		bool operator==(const Fixed &autre) const;
		bool operator!=(const Fixed &autre) const;

		Fixed operator+(const Fixed &autre) const;
		Fixed operator-(const Fixed &autre) const;
		Fixed operator*(const Fixed &autre) const;
		Fixed operator/(const Fixed &autre) const;

		Fixed & operator++(void); //pré-incrémentation
		Fixed operator++(int); // pos-incrémentation
		Fixed & operator--(void); //pré-décrémentation
		Fixed operator--(int); // pos-décrémentation

		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);

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
