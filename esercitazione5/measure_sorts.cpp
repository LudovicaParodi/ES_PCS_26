#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "quicksort.hpp"
#include "is_sorted.hpp"
#include "mergesort.hpp"
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"

#include "timecounter.h"
#include "randfiller.h"


int main()
{
    randfiller rf;

    std::vector<int> sizes = {15, 40, 60, 80, 100};

    for (int size : sizes)
    {
        std::vector<std::vector<int>> data(100, std::vector<int>(size));

        for (auto& v : data)
            rf.fill(v, -100, 100);

        timecounter tc;

        // -------- Bubble --------
        auto copy = data;
        tc.tic();
        for (auto& v : copy)
            bubblesort(v);
        double bubble = tc.toc() / 100;

        // -------- Insertion --------
        copy = data;
        tc.tic();
        for (auto& v : copy)
            insertionsort(v);
        double insertion = tc.toc() / 100;

        // -------- Selection --------
        copy = data;
        tc.tic();
        for (auto& v : copy)
            selectionsort(v);
        double selection = tc.toc() / 100;

        // -------- Quick --------
        copy = data;
        tc.tic();
        for (auto& v : copy)
            quicksort(v, 0, v.size()-1);
        double quick = tc.toc() / 100;

        // -------- Merge --------
        copy = data;
        tc.tic();
        for (auto& v : copy)
            mergesort(v, 0, v.size()-1);
        double merge = tc.toc() / 100;

        // -------- std::sort --------
        copy = data;
        tc.tic();
        for (auto& v : copy)
            std::sort(v.begin(), v.end());
        double stds = tc.toc() / 100;

        std::cout << "Size " << size << "\n";
        std::cout << "Bubble: " << bubble << "\n";
        std::cout << "Insertion: " << insertion << "\n";
        std::cout << "Selection: " << selection << "\n";
        std::cout << "Quick: " << quick << "\n";
        std::cout << "Merge: " << merge << "\n";
        std::cout << "std::sort: " << stds << "\n\n";
    }

    return 0;
}