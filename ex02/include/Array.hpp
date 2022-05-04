/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:26:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 21:50:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template < class T >
class Array
{
	public:
	typedef unsigned int	size_type;
	typedef T				&reference;
	typedef T const			&const_reference;
	typedef T				*pointer;

	private:
	size_type	array_size;
	pointer		internal;

	// --------------------------------------------------------------------- //

	public:
	class ArrayIndexOutOfBoundsException : public std::exception
	{
		public:
		virtual ~ArrayIndexOutOfBoundsException() throw() {}
		virtual char const	*what(void) const throw() { return "index out of bounds"; }
	}; // class ArrayIndexOutOfBoundsException

	Array(void) :
		array_size(0),
		internal(new T[0])
	{
	}

	Array(Array const &x) :
		array_size(x.array_size),
		internal(new T[x.array_size])
	{
		for (size_type i = 0; i < x.array_size; ++i)
			this->internal[i] = x.internal[i];
	}

	Array(size_type n) :
		array_size(n),
		internal(new T[n]())
	{
	}

	~Array()
	{
		delete[] this->internal;
	}

	Array &operator=(Array const &x)
	{
		if (this == &x)
			return (*this);
		this->~Array();
		this->array_size = x.array_size;
		this->internal = new T[this->array_size];
		for (size_type i = 0; i < this->array_size; ++i)
			(*this)[i] = x[i];
		return (*this);
	}

	// --------------------------------------------------------------------- //

	size_type size(void) const
	{
		return (this->array_size);
	}

	reference operator[](size_type index)
	{
		if (index >= this->array_size)
			throw ArrayIndexOutOfBoundsException();
		return (this->internal[index]);
	}

	const_reference operator[](size_type index) const
	{
		if (index >= this->array_size)
			throw ArrayIndexOutOfBoundsException();
		return (this->internal[index]);
	}
}; // class Array

#endif
