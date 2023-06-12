/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:02:22 by grenaud-          #+#    #+#             */
/*   Updated: 2023/06/11 23:24:03 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <bitset>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed& operator=(const Fixed &rhs);
		~Fixed();

		bool operator>(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		Fixed	operator--(int);
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator++();

		static Fixed	min(Fixed &fixed1, Fixed &fixed2);
		static Fixed	min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed	max(Fixed &fixed1, Fixed &fixed2);
		static Fixed	max(const Fixed &fixed1, const Fixed &fixed2);

		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		void	setRawBits(const int raw);
		void	print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif
