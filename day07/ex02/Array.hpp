/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:55:26 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/19 17:53:47 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	T* _array;
	unsigned _n;
	public:
		Array<T>(void) : _array(NULL), _n(0) {}
		Array<T>(unsigned n)
		{
			_n = n;
			_array = new T[n];
		}
		Array<T>(Array const &r)
		{
			*this = r;
		}
		Array<T> &operator=(const Array& r)
		{
			_n = r._n;
			delete _array;
			_array = new T[_n];
			for (unsigned i = 0; i < _n; ++i)
				_array[i] = r._array[i];
		}
		~Array<T>(void)
		{
			delete _array;
		}
		T& operator[](unsigned n)
		{
			if (n >= _n)
				throw std::out_of_range("Array index out of bounds");
			return _array[n];
		}
		unsigned size() const {return _n;}
};

#endif
