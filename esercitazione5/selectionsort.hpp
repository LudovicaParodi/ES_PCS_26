#include <iostream>
#include <vector>

template<typename T>
void selectionsort(std::vector<T>& A)
{
    for (int i=0; i<A.size()-1; i++)
    {
        int min_index = i;
        for (int j=i+1; j<A.size(); j++)
        {
            if (A[j]<A[min_index]) {
                min_index=j;
            }
        }
        if (min_index != i) {
            std::swap(A[i],A[min_index]);
        }
    }
}