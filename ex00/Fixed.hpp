/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:53 by christine         #+#    #+#             */
/*   Updated: 2023/12/04 17:03:31 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <c.math>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &autre);
	Fixed& operator=(const Fixed &autre);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);


	private:
	int _fixedNb;
	const static int _rawBits;
};

#endif
