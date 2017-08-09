/*
请设计一个高效算法，判断数组中是否有重复值。必须保证额外空间复杂度为O(1)。
给定一个int数组A及它的大小n，请返回它是否有重复值。
*/
// 只能先排序，再遍历，而且排序的空间复杂度还只能是O（1），所以只能使用非递归的堆排序

#include<vector>
#include <iostream>
using namespace std;

class Checker {
public:
    bool checkDuplicate(vector<int> a, int n) {
        build_heap(a, 0, n-1);
        heap_sort(a, 0, n-1);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i-1])  return true;
        }
        return false;
    }
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b; 
        b = tmp;
    }
    void down_heap(vector<int>& arr, int p, int right)
    {
        int child = 2*p + 1;
        while (child <= right)
        {
            if (child == right && arr[child] > arr[p])  swap(arr[p], arr[child]);
            if (child < right)
            {
                child = arr[child] > arr[child+1] ? child : child+1;
                if (arr[child] > arr[p])    swap(arr[p], arr[child]);
                else                        break;
            }
            p = child;
            child = 2*p + 1;
        }
    }
    void build_heap(vector<int>& arr, int left, int right)
    {
        int p = (right-1)/2;
        while (p >= left)   down_heap(arr, p--, right);
    }
    void heap_sort(vector<int>& arr, int left, int right)
    {
        while (right > left)
        {
            swap(arr[left], arr[right]);
            down_heap(arr, left, --right);
        }
    }
};

int main()
{
    vector<int> v = {1,2,3,2,8,5,4,3};
    Checker cc;
    cout << cc.checkDuplicate(v, 8) << endl;
    return 0;

}

