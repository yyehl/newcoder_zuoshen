class ShellSort {
public:
    int* shellSort(int* A, int n) {
       for (int gap = n/2; gap > 0; gap = gap/2)
       {
           for (int i = gap; i < n; i++)
           {
                int tmp = A[i];
                int j = i-gap;
                while (j >= 0 && A[j] > tmp)
                {
                    A[j+gap] = A[j];
                    j = j-gap;
                }
                A[j+gap] = tmp;
           }
       }
       return A;
    }
};