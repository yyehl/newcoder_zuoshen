class MergeSort {
public:
    int* mergeSort(int* A, int n) {
        int left = 0, right = n - 1, mid = left + (right - left) / 2;
        m_sort(A, left, mid);
        m_sort(A, mid+1, right);
        merge(A, left, mid, right);
        return A;
    }
    void m_sort(int* arr, int left, int right)
    {
        if (left >= right)  return ;
        int mid = left + (right - left) / 2;
        m_sort(arr, left, mid);
        m_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    void merge(int* arr, int left, int mid, int right)
    {
        int tmp[right-left+1];
        int l = left, r = mid+1;
        int i = 0;
        while (l <= mid && r <= right)
        {
            if (arr[l] <= arr[r])   tmp[i++] = arr[l++];
            else                    tmp[i++] = arr[r++];
        }
        while (l <= mid)    tmp[i++] = arr[l++];
        while (r <= right)  tmp[i++] = arr[r++];
        for (int j = 0; j < i; j++)   arr[left++] = tmp[j];
    }
};