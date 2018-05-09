#include <limits>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
	double value;
	ScalarConversion scalar;

	if (argc != 2)
		return 0;
	char *c_lit = argv[1];
	std::string str_lit = argv[1];
	if (str_lit == "-inf" || str_lit == "-inff")
		value = -std::numeric_limits<double>::infinity();
	else if (str_lit == "inf" || str_lit == "inff")
		value = std::numeric_limits<double>::infinity();
	else if (str_lit == "nan" || str_lit == "nanf")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (std::isprint(c_lit[0]) && !std::isdigit(c_lit[0]))
		value = static_cast<double>(c_lit[0]);
	else
		value = std::strtof(c_lit, NULL);
	pprintChar(scalar, value);
	pprintInt(scalar, value);
	pprintFloat(scalar, value);
	pprintDouble(scalar, value);
	std::cout << std::endl;
	return 0;
}
