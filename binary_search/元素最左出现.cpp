/*
对于一个有序数组arr，再给定一个整数num，请在arr中找到num这个数出现的最左边的位置。

给定一个数组arr及它的大小n，同时给定num。请返回所求位置。若该元素在数组中未出现，请返回-1。
测试样例：

[1,2,3,3,4],5,3

返回：2

*/

class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        int left = 0, right = n-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (num <= arr[mid])    right = mid-1;
            else    left = mid+1;
        }
        if (left == n || (left == 0 && arr[left] > num))    return -1;
        return left;
    }
};