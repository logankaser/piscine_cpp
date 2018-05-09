#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T& min(T const &a, T const &b)
{
	return (b > a ? a : b);
}

template <typename T>
const T& max(T const &a, T const &b)
{
	return (b > a ? b : a);
}

int main(void)
{
	int   a = 21;
	int   b = 42;

	::swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min(a, b): " << ::min(a, b) << std::endl;
	std::cout << "max(a, b): " << ::max(a, b) << std::endl;

	std::string s1 = "The Cake.";
	std::string s2 = "(Is a lie)";
	
	std::cout
		<< "s1: \"" << s1 << "\"; "
		<< "s2: \"" << s2 << "\";" << std::endl;
	std::cout << "Swapping.." << std::endl;
	::swap(s1, s2);
	std::cout
		<< "s1: \"" << s1 << "\"; "
		<< "s2: \"" << s2 << "\";" << std::endl;
	std::cout << "min(s1, s2): \"" << ::min(s1, s2) << '"' << std::endl;
	std::cout << "max(s1, s2): \"" << ::max(s1, s2) << '"' << std::endl;
	return 0;
}
