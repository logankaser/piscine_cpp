/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:52:19 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/19 18:10:09 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> arr(10);
	for (unsigned i = 0; i < 10; ++i)
		arr[i] = i;
	for (unsigned i = 0; i < 10; ++i)
		std::cout << arr[i];
	static char str[] = "Apple.\n";
	std::cout << std::endl;
	Array<char> str2(sizeof str);
	for (unsigned i = 0; i < sizeof str; ++i)
		str2[i] = str[i];
	for (unsigned i = 0; i < sizeof str; ++i)
		std::cout << str2[i];
	return 0;
}
