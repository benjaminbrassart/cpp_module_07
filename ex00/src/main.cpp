/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:54:17 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 18:09:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "whatever.hpp"

template < class T >
static void	__test_swap(T const a, T const b);
template < class T >
static void	__test_min(T const a, T const b);
template < class T >
static void	__test_max(T const a, T const b);

static void	_swap(void);
static void	_min(void);
static void	_max(void);

int	main(void)
{
	TEST_DECL() {
		TEST(_swap)
		TEST(_min)
		TEST(_max)
	};
	TEST_RUN();
}

template < class T >
static void	__test_swap(T const a, T const b)
{
	T	x(a);
	T	y(b);

	std::boolalpha(std::cout);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "a = " << x << ", b = " << y << std::endl;
		swap(x, y);
		std::cout << "a = " << x << ", b = " << y << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::noboolalpha(std::cout);
}

template < class T >
static void	__test_min(T const a, T const b)
{
	T	x(a);
	T	y(b);

	std::boolalpha(std::cout);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "a = " << x << ", b = " << y << ", min: " << min(x, y) << std::endl;
		swap(x, y);
		std::cout << "a = " << x << ", b = " << y << ", min: " << min(x, y) << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::noboolalpha(std::cout);
}

template < class T >
static void	__test_max(T const a, T const b)
{
	T	x(a);
	T	y(b);

	std::boolalpha(std::cout);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "a = " << x << ", b = " << y << ", max: " << max(x, y) << std::endl;
		swap(x, y);
		std::cout << "a = " << x << ", b = " << y << ", max: " << max(x, y) << std::endl;
		if (i > 0)
			std::cout << std::endl;
	}
	std::noboolalpha(std::cout);
}

static void	_swap(void)
{
	std::cout << "--- bool ---" << std::endl;
	__test_swap<bool>(true, false);
	std::cout << "--- int ---" << std::endl;
	__test_swap<int>(42, 69);
	std::cout << "--- double ---" << std::endl;
	__test_swap<double>(42.21, 69.96);
	std::cout << "--- std::string ---" << std::endl;
	__test_swap<std::string>("mocha", "jest");
}

static void	_min(void)
{
	std::cout << "--- bool ---" << std::endl;
	__test_min<bool>(true, false);
	std::cout << "--- int ---" << std::endl;
	__test_min<int>(42, 69);
	std::cout << "--- double ---" << std::endl;
	__test_min<double>(42.21, 69.96);
	std::cout << "--- std::string ---" << std::endl;
	__test_min<std::string>("mocha", "jest");
}

static void	_max(void)
{
	std::cout << "--- bool ---" << std::endl;
	__test_max<bool>(true, false);
	std::cout << "--- int ---" << std::endl;
	__test_max<int>(42, 69);
	std::cout << "--- double ---" << std::endl;
	__test_max<double>(42.21, 69.96);
	std::cout << "--- std::string ---" << std::endl;
	__test_max<std::string>("mocha", "jest");
}
