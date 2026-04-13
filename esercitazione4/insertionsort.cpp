#include <iostream>
#include <vector>

template<typename T>
void insertionsort(std::vector<T>& A)
{
    for(int i = 1; i<= A.size()-1; i++) 
    {
        T value = A[i];
        int j=i-1;
        while (j >= 0 && A[j]>value) 
        {
            std::swap(A[j+1],A[j]);
            j = j-1;
        }
        A[j+1]=value;
    }
    return;
}