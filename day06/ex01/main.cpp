#include <iostream>
#include <string>
#include <random>
#include <climits>

struct Data
{
	int n;
	std::string s1;
	std::string s2;
};

void *serialize(void)
{
	Data *d = new Data;
	static char set[] =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"1234567890";

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> pickset(0, sizeof(set) - 1);
	std::uniform_int_distribution<std::mt19937::result_type> picknum(INT_MIN, INT_MAX);
	for (unsigned i = 0; i < 8; ++i)
	{
		d->s1 += set[pickset(rng)];
		d->s2 += set[pickset(rng)];
	}
	d->n = picknum(rng);
	return (d);
}

Data *deserialize(void *raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main(void)
{
	void* srl = serialize();
	Data* dat = deserialize(srl);
	std::cout
		<< dat->s1 << std::endl
		<< dat->n << std::endl
		<< dat->s2 << std::endl;
	delete dat;
	return 0;
}
