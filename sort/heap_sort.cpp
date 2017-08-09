class HeapSort {
public:
    int* heapSort(int* A, int n) {
        build_heap(A, 0, n-1);
        heap_sort(A, 0, n-1);
        return A;
    }
    void down_heap(int arr[], int p, int right)
    {
        int child = 2*p + 1;
        if (child > right)  return ;
        if (child == right && arr[p] < arr[child])  swap(arr[p], arr[child]);
        if (child + 1 <= right)
        {
            child = arr[child] >= arr[child + 1] ? child : child + 1;
            if (arr[p] < arr[child])    swap(arr[p], arr[child]);
            else  return ;
        }
        down_heap(arr, child, right);
    }
    void build_heap(int arr[], int left, int right)
    {
        int p = (right-1)/2;
        while (p >= left)
            down_heap(arr, p--, right);
    }
    void heap_sort(int arr[], int left, int right)
    {
        while (right > left)
        {
            swap(arr[left], arr[right]);
            down_heap(arr, left, --right);
        }
    }
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b; 
        b = tmp;
    }
};