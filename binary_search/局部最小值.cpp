/*
定义局部最小的概念。arr长度为1时，arr[0]是局部最小。
arr的长度为N(N>1)时，如果arr[0]<arr[1]，那么arr[0]是局部最小；如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；
如果0<i<N-1，既有arr[i]<arr[i-1]又有arr[i]<arr[i+1]，那么arr[i]是局部最小。 
给定无序数组arr，已知arr中任意两个相邻的数都不相等，写一个函数，只需返回arr中任意一个局部最小出现的位置即可。 
*/

class Solution {
public:
    int getLessIndex(vector<int> arr) {
        if (arr.size() == 0)  return -1;
        return search_min_idx(arr, 0, arr.size()-1);
    }
    int search_min_idx(vector<int>& arr, int left, int right)
    {
        if (left >= right)  return left;
        else if (right - left == 2)     return arr[left] < arr[right] ? left : right;
        else if (arr[left] < arr[left+1])    return left;
        else if (arr[right] < arr[right-1])  return right;
        else 
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid-1])  return search_min_idx(arr, left+1, mid-1);
            else if (arr[mid] > arr[mid+1]) return search_min_idx(arr, mid+1, right-1);
            else    return mid;
        }
    }
};