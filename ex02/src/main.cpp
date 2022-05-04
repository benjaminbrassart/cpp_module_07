/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:42:18 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 21:53:14 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "tests.h"

template < class T >
static void	__array_access(Array<T> &array, typename Array<T>::size_type index, std::string const &array_name = "array");

static void	_int(void);
static void	_double(void);
static void	_uchar(void);
static void	_array(void);

int	main(void)
{
	TEST_DECL() {
		TEST(_int)
		TEST(_double)
		TEST(_uchar)
		TEST(_array)
	};
	TEST_RUN();
}

static void	_int(void)
{
	Array<int>	ar1;
	Array<int>	ar2(15);
	Array<int>	*ar3;

	ar3 = new Array<int>(20);

	ar2[5] = 55;
	(*ar3)[13] = 4;

	__array_access(ar1, 0, "ar1");
	__array_access(ar1, 2, "ar1");
	__array_access(ar1, 4, "ar1");
	__array_access(ar1, 5, "ar1");
	std::cout << std::endl;
	__array_access(ar2, 0, "ar2");
	__array_access(ar2, 2, "ar2");
	__array_access(ar2, 4, "ar2");
	__array_access(ar2, 5, "ar2");
	std::cout << std::endl;
	__array_access(*ar3, 0, "ar3");
	__array_access(*ar3, 2, "ar3");
	__array_access(*ar3, 4, "ar3");
	__array_access(*ar3, 5, "ar3");
	__array_access(*ar3, 13, "ar3");
	delete ar3;
}

static void	_double(void)
{
	Array<double>	ar1;
	Array<double>	ar2(15);
	Array<double>	*ar3;

	ar3 = new Array<double>(20);

	ar2[5] = 55.2;
	(*ar3)[13] = -9.6;

	__array_access(ar1, 0, "ar1");
	__array_access(ar1, 2, "ar1");
	__array_access(ar1, 4, "ar1");
	__array_access(ar1, 5, "ar1");
	std::cout << std::endl;
	__array_access(ar2, 0, "ar2");
	__array_access(ar2, 2, "ar2");
	__array_access(ar2, 4, "ar2");
	__array_access(ar2, 5, "ar2");
	std::cout << std::endl;
	__array_access(*ar3, 0, "ar3");
	__array_access(*ar3, 2, "ar3");
	__array_access(*ar3, 4, "ar3");
	__array_access(*ar3, 5, "ar3");
	__array_access(*ar3, 13, "ar3");
	delete ar3;
}

static void	_uchar(void)
{
	Array<unsigned char>	ar1;
	Array<unsigned char>	ar2(15);
	Array<unsigned char>	*ar3;

	ar3 = new Array<unsigned char>(20);

	ar2[5] = '}';
	(*ar3)[13] = 'c';

	__array_access(ar1, 0, "ar1");
	__array_access(ar1, 2, "ar1");
	__array_access(ar1, 4, "ar1");
	__array_access(ar1, 5, "ar1");
	std::cout << std::endl;
	__array_access(ar2, 0, "ar2");
	__array_access(ar2, 2, "ar2");
	__array_access(ar2, 4, "ar2");
	__array_access(ar2, 5, "ar2");
	std::cout << std::endl;
	__array_access(*ar3, 0, "ar3");
	__array_access(*ar3, 2, "ar3");
	__array_access(*ar3, 4, "ar3");
	__array_access(*ar3, 5, "ar3");
	__array_access(*ar3, 13, "ar3");
	delete ar3;
}

static void	_array(void)
{
	Array< Array<int> >	array(3);

	array[0] = Array<int>(2);
	array[1] = Array<int>(3);
	array[2] = Array<int>(4);
	array[0][0] = 13;
	array[0][1] = 99;
	array[1][0] = -1;
	array[1][1] = 2;
	array[1][2] = 199993;
	array[2][0] = -1;
	array[2][1] = -3333;
	array[2][2] = 111;
	array[2][3] = 424242;

	for (Array< Array<int> >::size_type i = 0; i < array.size(); ++i)
	{
		std::cout << "array[" << i << "]" << std::endl;
		for (Array<int>::size_type j = 0; j < array[i].size(); ++j)
		{
			std::cout << "[" << j << "] " << array[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}

template < class T >
static void	__array_access(Array<T> &array, typename Array<T>::size_type index, std::string const &array_name)
{
	std::cout << array_name << "[" << index << "] = ";
	try
	{
		typename Array<T>::reference t = array[index];

		std::cout << t;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m";
	}
	std::cout << std::endl;
}
