/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:02:28 by grenaud-          #+#    #+#             */
/*   Updated: 2023/06/12 14:36:30 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(): _value(0)
{	
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	//std::cout << "Copy constructor called" << std::endl;
	_value = rhs._value;
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_value = rhs._value;
	return *this;
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	_value = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int		Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

void	Fixed::print(std::ostream &os) const 
{
    float floatValue = toFloat();
    os << floatValue;
}

std::ostream& operator<<(std::ostream &os, const Fixed &number) 
{
    number.print(os);
    return os;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return _value > rhs._value;
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return _value >= rhs._value;
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return _value < rhs._value;
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return _value <= rhs._value;
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return _value == rhs._value;
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return _value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result._value = this->_value + rhs._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result._value = this->_value - rhs._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	result._value = (this->_value * rhs._value) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	result._value = (this->_value << _fractionalBits) / rhs._value;
	return result;
}

//--i, renvoie la valeur originale avant decrementation 
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    this->_value--;
	//--(*this);
    return temp;
}

Fixed Fixed::operator--() 
{
    this->_value--;
	//_value -= (1 << _fractionalBits);
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
	this->_value++;
    //++(*this);
    return temp;
}

Fixed Fixed::operator++() 
{
    this->_value++;
	 //_value += (1 << _fractionalBits);
    return *this;
}

Fixed Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed2);
	return (fixed1);
}
