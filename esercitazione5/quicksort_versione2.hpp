#include <iostream>
#include <vector>

template<typename T>
int partition(std::vector<T>& A, int p, int r)
{
    T pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i+1], A[r]);
    return i + 1;
}
template<typename T>

void quicksort(std::vector<T>& A, int p, int r)
{
    const int THRESHOLD = 15;

    if (p < r)
    {
        if (r - p + 1 <= THRESHOLD)
        {
            insertionsort(A); 
        }
        else
        {
            int q = partition(A, p, r);
            quicksort(A, p, q - 1);
            quicksort(A, q + 1, r);
        }
    }
}