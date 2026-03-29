#include "rational.hpp"
#include <iostream>

int main()
{
	rational<int> a(3,-6);
	rational<int> b(3,5);

	rational<int> c = a+b;

	std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
	
	return 0;
}
