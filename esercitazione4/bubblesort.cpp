#include <iostream>
#include <vector>

template<typename T>

void bubblesort(std::vector<T>& A)
{
    for (int i=0; i <= A.size()-2; i++) {
        for (int j=A.size()-1; j>=i+1; j--) {
            if (A[j]<A[j-1]) {
                std::swap(A[j],A[j-1]);
            }
        }
    }
}

