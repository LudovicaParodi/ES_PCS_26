#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <cstring>

int main()
{
    std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
	static const int N = 10;
    std::vector<int>::iterator result = std::min_element(v.begin(), v.end());
    std::cout << "il minimo ha valore " << *result << " e indice ["
              << std::distance(v.begin(), result) << "]\n";

    std::vector<int>::iterator result1 = std::max_element(v.begin(), v.end());
    std::cout << "il massimo ha valore " << *result1              
              << " e indice ["  << std::distance(v.begin(), result1)<< "]\n";
	double media = 0;		
	double somma = 0;
    for (int i = 0; i < N; i++) {
			somma = somma + v[i];
		}
	media = somma/N;			
	std::cout << "la media è "<< media << "\n";
	double variazione=0;
    double somma2 = 0;
	for (int i = 0; i < N; i++) {
		somma2 = somma2 + std::pow((v[i]-media), 2);
	}
	variazione=somma2/N;
	std::cout<< "la variazione standard è " << std::sqrt(variazione) << '\n';
}