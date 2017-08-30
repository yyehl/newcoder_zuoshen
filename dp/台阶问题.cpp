/*
有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。为了防止溢出，请将结果Mod 1000000007
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
测试样例：
1
返回：1
*/
// 暴力搜索法
class GoUpstairs {
public:
    int countWays(int n) {
        if (n == 0)     return 0;
        if (n == 1)     return 1;
        if (n == 2)     return 2;
        return (countWays(n-1) + countWays(n-2)) % 1000000007;
    }
};
// 记忆搜索法
class GoUpstairs {
public:
    int countWays(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        return foo(n, dp);
    }
    int foo(int n, vector<int>& dp)
    {
        if (dp[n] != -1)    return dp[n];
        else 
        {
            long long ret = (foo(n-1) + foo(n-2)) % 1000000007;
            dp[n] = ret;
            return ret;
        }
    }
};
// 动态规划
class GoUpstairs {
public:
    int countWays(int n) {
        if (n == 0)     return 0;
        if (n == 1)     return 1;
        if (n == 2)     return 2;
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        return dp[n];
    }
};
// 空间O（1）的dp
class GoUpstairs {
public:
    int countWays(int n) {
        if (n < 3)      return n;
        int prev = 2, last = 1;
        int ret;
        for (int i = 3; i <= n; i++)
        {
            ret = (prev + last) % 1000000007;
            prev = ret;
            last = prev;
        }
        return ret;
    }
};