/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:40:15 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 19:17:19 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 4 && strlen(argv[2]) > 0 && strlen(argv[3]) > 0) {
		std::ifstream f(argv[1]);
		std::string str((std::istreambuf_iterator<char>(f)),
			std::istreambuf_iterator<char>());
		size_t index = 0;
		while (true) {
    		index = str.find(argv[2], index);
    	 	if (index == std::string::npos)
				break;
			size_t len = strlen(argv[2]);
     		str.replace(index, len, argv[3]);
     		index += len;
		}
		std::string name(argv[1]);
		std::ofstream out(name + ".replace");
		out << str;
		out.close();
		std::cout << "Replacment complete" << std::endl;
	}
	else
		std::cout << "Error usage" << std::endl;
	return (0);
}
