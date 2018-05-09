#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void) {}
ScalarConversion::ScalarConversion(const ScalarConversion &other) {*this = other;}
ScalarConversion::~ScalarConversion(void) {}
ScalarConversion& ScalarConversion::operator=(const ScalarConversion&) {return *this;}

char ScalarConversion::convertToChar(double d)
{
	char	c;

	if (std::isnan(d))
		throw ScalarConversion::Impossible();
	c = static_cast<char>(d);
	if (!std::isprint(c))
		throw ScalarConversion::NonDisplayable();
	return (c);
}

int ScalarConversion::convertToInt(double d)
{
	if (std::isnan(d) || std::isinf(d))
		throw ScalarConversion::Impossible();
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		throw ScalarConversion::Impossible();
	return (static_cast<int>(d));
}

float ScalarConversion::convertToFloat(double d)
{
	return (static_cast<float>(d));
}

double ScalarConversion::convertToDouble(double d)
{
	 return (static_cast<double>(d));
}

const char* ScalarConversion::NonDisplayable::what(void) const throw()
{
	return("Non Displayable");
}

const char* ScalarConversion::Impossible::what(void) const throw()
{
	return("Impossible");
}

void pprintChar(ScalarConversion scalar, double value)
{
	std::cout << "char: ";
	try
	{
		std::cout << "'" << scalar.convertToChar(value) << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "'" << std::endl;
	}
}

void pprintInt(ScalarConversion scalar, double value)
{
	std::cout << "int: ";
	try
	{
		std::cout << scalar.convertToInt(value) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void pprintDouble(ScalarConversion scalar, double value)
{
	std::cout << "double: ";
	try
	{
		std::cout << scalar.convertToDouble(value) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void pprintFloat(ScalarConversion scalar, double value)
{
	std::cout << "float: ";
	try
	{
		std::cout	<< scalar.convertToFloat(value) << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
