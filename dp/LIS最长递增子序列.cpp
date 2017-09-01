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
        return foo(A, INT_MIN, 0);
    }
    int foo(const vector<int>& arr, int prev, int pos)
    {
        if (pos == arr.size())  return 0;
        int token = 0, notoken = 0;
        if (arr[pos] > prev)  token = 1 + foo(arr, arr[pos], pos+1);
        notoken = foo(arr, prev, pos+1);
        return max(token, notoken);
    }
};
// 记忆搜索法
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        if (n <= 1)     return n;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return foo(A, -1, 0, dp);
    }
    int foo(const vector<int>& arr, int prev, int pos, vector<vector<int>>& dp)
    {
        if (pos == arr.size())  return 0;
        if (dp[prev+1][pos] != -1)    return dp[prev+1][pos];
        int token = 0, notoken = 0;
        if (prev < 0 || arr[pos] > arr[prev])   token = 1 + foo(arr, pos, pos+1, dp);
        notoken = foo(arr, prev, pos+1, dp);
        return dp[prev+1][pos] = max(token, notoken);
    }
};
// 动态规划法
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        if (n <= 1)     return n;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int maxc = 0;
            for (int j = i-1; j >= 0; j--)
                if (A[j] < A[i])    maxc = max(maxc, dp[j]);
            dp[i] = maxc + 1;
        }
        int ret = 0;
        for (int i = 0; i < n; i++)     ret = max(ret, dp[i]);
        return ret;
    }
};