/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:30:30 by christine         #+#    #+#             */
/*   Updated: 2023/12/04 22:26:32 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_rawBits = 8;

Fixed::Fixed() : _fixedNb(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedNb = nb << this->_rawBits;
}

Fixed::Fixed(const float nb)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedNb = roundf(nb * (1 << this->_rawBits));
}

Fixed::Fixed(const Fixed &autre)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = autre;
}
Fixed& Fixed::operator=(const Fixed &autre)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &autre)
		this->_fixedNb = autre.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &autre) const
{
	if (this->_fixedNb > autre._fixedNb)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &autre) const
{
	if (this->_fixedNb < autre._fixedNb)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &autre) const
{
	if (this->_fixedNb >= autre._fixedNb)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &autre) const
{
	if (this->_fixedNb <= autre._fixedNb)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &autre) const
{
	if (this->_fixedNb == autre._fixedNb)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &autre) const
{
	if (this->_fixedNb != autre._fixedNb)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &autre) const
{
	return (Fixed(this->toFloat() + autre.toFloat()));
}

Fixed Fixed::operator-(const Fixed &autre) const
{
	return (Fixed(this->toFloat() - autre.toFloat()));
}

Fixed Fixed::operator*(const Fixed &autre) const
{
	return (Fixed(this->toFloat() * autre.toFloat()));
}

Fixed Fixed::operator/(const Fixed &autre) const
{
	return (Fixed(this->toFloat() / autre.toFloat()));
}

Fixed & Fixed::operator++(void)  //pré-incrémentation
{
	this->_fixedNb += 1;
	return (*this);
}

Fixed Fixed::operator++(int) // pos-incrémentation
{
	Fixed duplicate = *this;

	this->_fixedNb += 1;
	return (duplicate);
}

Fixed & Fixed::operator--(void)
{
	this->_fixedNb -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed duplicate = *this;

	this->_fixedNb -= 1;
	return (duplicate);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
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
