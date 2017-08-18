/*
对于一个有序循环数组arr，返回arr中的最小值。有序循环数组是指，有序数组左边任意长度的部分放到右边去，右边的部分拿到左边来。
比如数组[1,2,3,3,4]，是有序循环数组，[4,1,2,3,3]也是。
给定数组arr及它的大小n，请返回最小值。
测试样例：
[4,1,2,3,3],5
返回：1
*/
#include <vector>
#include <iostream>
using namespace std;


class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        if (n == 0) return -1;
        if (n == 1) return 0;
        int left = 0, right = n-1;
        while (left < right)
        {
            if (left == right - 1)   return min(arr[left], arr[right]);
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right])   left = mid;
            else if (arr[mid] < arr[right])   right = mid;
            else   // arr[mid] == arr[left]
            {
                if (arr[mid] == arr[left]) break;
                else if (arr[mid] < arr[left])   right = mid;
                else if (arr[mid] > arr[left])   return arr[left];
            }
        }
        if (left < right)  
        {
            int res = arr[0];
            for (int i = 0; i < n; i++)
                res = min(res, arr[i]);
            return res;
        }
        return arr[left];
    }
};
int main()
{
    vector<int> v = {4,5,6,7,1,2,3};
    MinValue mm;
    int res = mm.getMin(v, v.size());
    cout << res << endl;
    return 0;
}

