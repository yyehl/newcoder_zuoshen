#include <stdlib.h>
#include <utility>
using namespace std;

class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j > i; j--)
            {
                if (A[j] < A[j-1])
                    swap(A[j], A[j-1]);
            }
        }
        return A;
    }
};