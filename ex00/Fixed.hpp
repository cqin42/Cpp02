/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:07:34 by cqin              #+#    #+#             */
/*   Updated: 2023/12/01 13:14:17 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
  public:
	Fixed();
	// My(MyClass &&) = default;
	// MyClass(const MyClass &) = default;
	// MyClass &operator=(MyClass &&) = default;
	// MyClass &operator=(const MyClass &) = default;
	~Fixed();

  private:
	int _n;
	static const int _bits;
};

#endif // !FIXED_HPP#define FIXED_HPP
