/*
已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，
每个元素移动的距离可以不超过k，并且k相对于数组来说比较小。
请选择一个合适的排序算法针对这个数据进行排序。
给定一个int数组A，同时给定A的大小n和题意中的k，请返回排序后的数组。
*/
#include <vector>
#include <iostream>
using namespace std;

class ScaleSort {
public:
    vector<int> sortElement(vector<int> A, int n, int k) {
        int left = 0;
        vector<int> ret(n);
        build_heap(A, 0, k-1);
        int i = 0, j = k;
        while (j < n)
        {
            ret[i] = A[0];
            swap(A[j], A[0]);
            down_heap(A, 0, k-1);
            i++, j++;
        }
        j = k-1;
        while (j >= 0)
        {
            ret[i] = A[0];
            swap(A[0], A[j]);
            down_heap(A, 0, --j);
            i++;
        }
        return ret;
    }
    void down_heap(vector<int>& arr, int p, int right)
    {
        int child = 2*p + 1;
        while (child <= right)
        {
            if (child == right && arr[child] < arr[p])  swap(arr[child], arr[p]);
            if (child < right)
            {
                child  = arr[child] < arr[child+1] ? child : child + 1;
                if (arr[child] < arr[p])    swap(arr[child], arr[p]);
                else                        break;
            }
            p = child;
            child = 2*p + 1;
        }
    }
    void build_heap(vector<int>& arr, int left, int right)
    {
        int p = (right - 1) / 2;
        while (p >= left)   
            down_heap(arr, p--, right);
    }
};

int main()
{
    vector<int> v = {1,3,2,4,5,7,6,8,9};
    ScaleSort ss;
    vector<int> ret = ss.sortElement(v, 9, 3);
    for (auto i: v) cout << i << " "; cout << endl;
    for (auto i: ret) cout << i << " "; cout << endl;
    return 0;
}