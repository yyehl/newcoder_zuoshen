/*
有一个整形数组A，请设计一个复杂度为O(n)的算法，算出排序后相邻两数的最大差值。
给定一个int数组A和A的大小n，请返回最大的差值。保证数组元素多于1个。
*/

#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Gap {
public:
    int maxGap(vector<int> A, int n) {
        int max_num = A[0];
        int min_num = A[0];
        double x;
        for (int i = 1; i < n; i++)
        {
            max_num = max(max_num, A[i]);
            min_num = min(min_num, A[i]);
        }
        x = static_cast<double>(max_num - min_num) / static_cast<double>(n);
        vector<int> bucket_max(n+1, INT_MAX);
        vector<int> bucket_min(n+1, INT_MIN);
        for (int i = 0; i < n; i++)
        {
            int m = static_cast<double>(A[i] - min_num) / x;
            if (bucket_min[m] == INT_MIN)   bucket_min[m] = A[i];
            else if (bucket_max[m] == INT_MAX)
            {
                if (A[i] > bucket_min[m])   bucket_max[m] = A[i];
                else if (A[i] < bucket_min[m])
                {
                    bucket_max[m] = bucket_min[m];
                    bucket_min[m] = A[i];
                }
            }
            else
            {
                if (A[i] > bucket_max[m])   bucket_max[m] = A[i];
                else if (A[i] < bucket_min[m])  bucket_min[m] = A[i];
            }

        }
        int count = 0, l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (bucket_min[i] == INT_MIN)   
            {
                int a = i-1, b = i+1;
                int tmp_count = 1;
                while (bucket_min[i+1] == INT_MIN)
                {
                    b++, i++, tmp_count++;
                }   
                if (count = tmp_count)
                {
                    int tmp1, tmp2;
                    tmp1 = bucket_max[l] == INT_MAX ? bucket_min[r] - bucket_min[l] : bucket_min[r] - bucket_max[l];
                    tmp2 = bucket_max[a] == INT_MAX ? bucket_min[b] - bucket_min[a] : bucket_min[b] - bucket_max[a];
                    if (tmp1 < tmp2)
                    {
                        l = a, r = b, count = tmp_count;
                    }
                }
                else if (count < tmp_count)
                    l = a, r = b, count + tmp_count;
            }
        }
        int ret = bucket_max[l] == INT_MAX ? bucket_min[r] - bucket_min[l] : bucket_min[r] - bucket_max[l];
        return ret;
    }
};