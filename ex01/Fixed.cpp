/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:30:30 by christine         #+#    #+#             */
/*   Updated: 2023/12/04 19:54:13 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_rawBits = 8;

Fixed::Fixed() : _fixedNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNb = nb << this->_rawBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNb = roundf(nb * (1 << this->_rawBits));
}

Fixed::Fixed(const Fixed &autre)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = autre;
}
Fixed& Fixed::operator=(const Fixed &autre)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &autre)
		this->_fixedNb = autre.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const
{
	return (float(this->_fixedNb) / (1 << this->_rawBits));
}

int Fixed::toInt(void) const
{
	return (int(this->_fixedNb >> this->_rawBits));
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedNb);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNb = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const &nb)
{
	o<< nb.toFloat();
	return o;
}
