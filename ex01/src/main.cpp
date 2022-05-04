/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:13:47 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 18:23:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "tests.h"

template < class T >
static void __instanciated_template_function(T const &x)
{
	std::cout << x << std::endl;
}

template < >
void __instanciated_template_function<int>(int const &x)
{
	std::cout << "int specialization: " << (x * x) << std::endl;
}

template < >
void __instanciated_template_function<double>(double const &x)
{
	std::cout << "double specialization: " << (x * x) << std::endl;
}

static void _int(void);
static void _double(void);
static void _string(void);

int	main(void)
{
	TEST_DECL() {
		TEST(_int)
		TEST(_double)
		TEST(_string)
	};
	TEST_RUN();
}

static void _int(void)
{
	int	array[] = {1, 2, 4, 8, 16};

	iter(array, sizeof (array) / sizeof (*array), __instanciated_template_function);
}

static void _double(void)
{
	double	d = 99.5;

	iter(&d, 1, __instanciated_template_function);
}

static void _string(void)
{
	std::string	array[] = {"hello", "world", "!"};
	iter(array, sizeof (array) / sizeof (*array), __instanciated_template_function);
}
