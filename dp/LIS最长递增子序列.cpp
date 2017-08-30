/*
这是一个经典的LIS(即最长上升子序列)问题，请设计一个尽量优的解法求出序列的最长上升子序列的长度。
给定一个序列A及它的长度n(长度小于等于500)，请返回LIS的长度。
测试样例：
[1,4,2,5,3],5
返回：3
*/
// 暴力搜索法
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        if (n <= 1)     return n;
        return foo(A, 0);
    }
    int foo(const vector<int>& arr, int index)
    {
        if (index == arr.size()-1)      return 1;
        int max_len = 0;
        for (int i = index + 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[index])
                max_len = max(max_len, 1 + foo(arr, i));
        }
        return max_len;
    }
};
// 记忆搜索法
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        if (n <= 1)     return n;
        int dp[n];
        for (int i = 0; i < n; i++)   dp[i] = 0;
        return foo(A, 0, n)
    }
    int foo(const vector<int>& arr, int index, int n)
    {
        if (dp[index] != 0)     return dp[index];
        else 
        {
            if (index == n-1)   return dp[index] = 1;
            int max_len = 1;
            for (int i = index + 1; i < n; i++)
            {
                if (arr[i] > arr[index])    
                    max_len = max(max_len, 1 + foo(arr, i, n));
            }
            return dp[index] = max_len;
        }
    }
};
// 动态规划法
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        // write code here
    }
};