/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:00:18 by christine         #+#    #+#             */
/*   Updated: 2023/12/05 12:02:41 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// const static int _rawBits = 8;

Fixed::Fixed() : _fixedNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &autre)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = autre;
}
Fixed &Fixed::operator=(const Fixed &autre)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &autre)
		this->_fixedNb = autre.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNb);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNb = raw;
}
