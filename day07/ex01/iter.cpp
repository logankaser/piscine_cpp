#include <iostream>

template <typename T>
void iter(T *array, unsigned length, void (*f)(const T&))
{
	if (array)
		for (unsigned i = 0; i < length; ++i)
			f(array[i]);
}

template <typename T>
void print(const T& element)
{
	std::cout << element << ", ";
}

int main(void)
{
	int ints[] = {4, 8, 15, 15, 23, 42};
	std::cout << "Integers: ";
	iter <int>(ints, 6, print);
	std::cout << std::endl;

	std::string strs[] = {
		"Cow", "Not Cow",
		"Plane", "Bike",
		"Coffee", "Also not cow"
	};
	std::cout << "Strings: ";
	iter(strs, 6, print);
	std::cout << std::endl;
	return 0;
}
