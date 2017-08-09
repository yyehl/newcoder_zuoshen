/*
对于一个数组，请设计一个高效算法计算需要排序的最短子数组的长度。
给定一个int数组A和数组的大小n，请返回一个二元组，代表所求序列的长度。
(原序列位置从0开始标号,若原序列有序，返回0)。保证A中元素均为正整数。
*/

#include <vector>
#include <iostream>
using namespace std;

class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        int max_num = A[0], min_num = A[n-1], left_index = 0, right_index = n-1;
        for (int i = 1; i < n; i++)
        {
            max_num = max(A[i], max_num);
            left_index = A[i] < max_num ? i : left_index;
        }
        for (int i = n-2; i >= 0; i--)
        {
            min_num = min(A[i], min_num);
            right_index = A[i] > min_num ? i : right_index;
        }
        if (left_index <= right_index)  return 0;
        return left_index - right_index + 1;
    }
};