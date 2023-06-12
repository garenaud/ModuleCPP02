/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:02:32 by grenaud-          #+#    #+#             */
/*   Updated: 2023/06/11 23:26:58 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main( void ) 
{
 	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
/* 	Fixed num1(15);
	Fixed num2(6.986f);
	std::cout << "num2._value = " << num2.getRawBits() << std::endl;
	std::cout << "num2._value = " << std::bitset<16>(num2.getRawBits()) << std::endl;
	std::cout << num2 << std::endl;
	num2++;
	std::cout << num2 << std::endl;
	int	ex1 = 42;
	int	ex2 = -42;
	std::cout << "\033[32mnum1(15) = "<< std::bitset<8>(ex1)  << " num1(10) = "<< std::bitset<8>(ex2) << std::endl;
	std::cout << " num1 * num2 "<< std::bitset<8>(ex1 * ex2) << std::endl;
	std::cout << " num1 * num2 >> 1 "<< num1 << " " << std::bitset<8>((ex1 * ex2) >> 1) << std::endl;
	std::cout << " num1 * num2 >> 8 "<< num1 << " \033[0m" << std::bitset<8>((ex1 * ex2) >> 8) << std::endl << std::endl;
	Fixed addition;
	Fixed soustraction;
	Fixed multi;
	Fixed div;

	if (num1 > num2) {
		std::cout << "num1 est plus grand que num2" << std::endl;
	}
	if (num1 < num2) {
		std::cout << "num2 est plus grand que num1" << std::endl;
	}

	if (num1 == num2) {
		std::cout << "num1 est égal à num2" << std::endl;
	}
	addition = num1 + num2;
	soustraction = num1 - num2;
	multi = num1 * num2;
	div = num1 / num2;
	std::cout << soustraction << std::endl;
	std::cout << multi << std::endl;
	std::cout << div << std::endl; */
	return 0;
}
