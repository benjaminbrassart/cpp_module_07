/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:49:52 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 18:01:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// swap

template < class T >
void swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

// min / max (const)

template < class T >
T const &min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template < class T >
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

// min / max

template < class T >
T &min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template < class T >
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
