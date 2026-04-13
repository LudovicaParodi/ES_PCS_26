#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include "timecounter.h"
#include "randfiller.h"
#include "bubblesort.cpp"
#include "insertionsort.cpp"
#include "selectionsort.cpp"
#include "is_sorted.cpp"

int main(void)
{
    randfiller rf;
    for(int i=4; i<=8192; i*=2) {  
        std::vector<int> vi; 
        vi.resize(i);     
        rf.fill(vi, -100, 100);            
        

        std::vector<int> v1 = vi;
        std::vector<int> v2 = vi;
        std::vector<int> v3 = vi;
        std::vector<int> v4 = vi;

        timecounter tc;

        tc.tic();
        bubblesort(v1);
        double secs1=tc.toc();
        std::cout << "Bubble sort (" << i << "): "
                  << secs1 << " seconds\n";

        tc.tic();
        insertionsort(v2);
        double secs2=tc.toc();
        std::cout << "Insertion sort (" << i << "): "
                  << secs2 << " seconds\n";

        tc.tic();
        selectionsort(v3);
        double secs3=tc.toc();
        std::cout << "Selection sort (" << i << "): "
                  << secs3 << " seconds\n";

        tc.tic();
        std::sort(v4.begin(), v4.end());
        double secs4=tc.toc();
        std::cout << "std::sort (" << i << "): "
                  << secs4 << " seconds\n";
    }

    return EXIT_SUCCESS;
}