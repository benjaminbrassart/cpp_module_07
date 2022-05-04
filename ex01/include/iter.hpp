/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:11:23 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 18:20:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template < class T >
void iter(T const array[], unsigned int array_size, void (*func)(T const &))
{
	for (unsigned int i = 0; i < array_size; ++i)
		func(array[i]);
}

#endif
