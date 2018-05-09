#include <random>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> pickBase(0, 2);
	switch (pickBase(rng))
	{
		case 0:
			std::cout << "Class A generated!" << std::endl;
			return new A();
		case 1:
			std::cout << "Class B generated!" << std::endl;
			return new B();
		default:
			std::cout << "Class C generated!" << std::endl;
			return new C();
	}
}

void identify_from_pointer(Base *ptr)
{
	A* a = dynamic_cast<A*>(ptr);
	B* b = dynamic_cast<B*>(ptr);
	C* c = dynamic_cast<C*>(ptr);
	if (a)
		std::cout << "A identified" << std::endl;
	else if (b)
		std::cout << "B identified" << std::endl;
	else if (c)
		std::cout << "C identified" << std::endl;
}

void identify_from_reference(Base &ref)
{
	identify_from_pointer(&ref);
}

int main(void)
{
	Base* ptr = generate();

	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	return 0;
}
