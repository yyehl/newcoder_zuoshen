

class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        for (int i = 1; i < n; i++)
        {
            int j = i-1;
            int key = A[i];
            while (j >= 0 && key < A[j])
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = key;
        }
        return A;
    }
};