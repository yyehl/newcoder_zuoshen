#include <utility>

class QuickSort {
public:
    int* quickSort(int* A, int n) {
        int left = 0, right = n-1;
        q_sort(A, left, right);
        return A;
    }
    void q_sort(int arr[], int left, int right)
    {
        if (left >= right)  return ;
        int l = left, r = right-1, p = arr[right];
        while (1)
        {
            while (arr[l] < p)  l++;
            while (arr[r] > p)  r--;
            if (l < r)
                std::swap(arr[l++], arr[r--]);
            else 
                break;
        }
        std::swap(arr[l], arr[right]);
        q_sort(arr, left, l-1);
        q_sort(arr, l+1, right);
    }
};