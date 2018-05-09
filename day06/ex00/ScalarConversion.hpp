#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <climits>
#include <iostream>

class ScalarConversion
{
	public:
	struct NonDisplayable : public std::exception
	{
		const char	*what(void) const throw();
	};
	struct Impossible : public std::exception
	{
		const char	*what(void) const throw();
	};
	ScalarConversion(void);
	ScalarConversion(const ScalarConversion &);
	~ScalarConversion(void);
	ScalarConversion& operator=(const ScalarConversion &);

	static int getPrecision(char *str);
	static char convertToChar(double d);
	static int convertToInt(double d);
	static double convertToDouble(double d);
	static float convertToFloat(double d);
};

void pprintChar(ScalarConversion scalar, double value);
void pprintInt(ScalarConversion scalar, double value);
void pprintDouble(ScalarConversion scalar, double value);
void pprintFloat(ScalarConversion scalar, double value);

#endif
