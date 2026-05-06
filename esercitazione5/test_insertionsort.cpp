#include <iostream>
#include <vector>
#include <string>
#include "is_sorted.hpp"
#include "insertionsort.hpp"
#include "randfiller.h"

template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{
    randfiller rf; 
    for (int i=1; i<101; i++) {
        int dimensionecasuale = 1 + (std::rand() % 100);
        std::vector<int> vi;
        vi.resize(dimensionecasuale);
        rf.fill(vi, -100, 100); 
        insertionsort(vi);

        if (!is_sorted(vi)) {
            return EXIT_FAILURE;
        }
    }
    
    std::vector<std::string> s = {
        "casa","giardino","amaca","zebra","mollica",
        "balena","scarpa","lampione","computer","padrone"
    };

    insertionsort(s);

    if (!is_sorted(s)) 
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}