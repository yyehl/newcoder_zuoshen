#include <utility>
using namespace std;

class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        for (int i = 0; i < n; i++)
        {
            int min_index = i;
            for (int j = i+1; j < n; j++)
				min_index = A[j] < A[min_index] ? j : min_index;
            swap(A[min_index], A[i]);
        }
        return A;
    }
};