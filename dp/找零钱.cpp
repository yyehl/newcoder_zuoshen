/*
有数组penny，penny中所有的值都为正数且不重复。
每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个整数aim(小于等于1000)代表要找的钱数，求换钱有多少种方法。
给定数组penny及它的大小(小于等于50)，同时给定一个整数aim，请返回有多少种方法可以凑成aim。
测试样例：
[1,2,4],3,3
返回：2
暴力搜索 -> 记忆化搜索 -> 动态规划 -> 优化过后的动态规划
*/

// 暴力搜索法
class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        if (penny.empty() || aim == 0)  return 0;
        return foo(penny, 0, aim);
    }
    int foo(const vector<int>& arr, int index, int aim)
    {
        if (aim == 0)   return 1;
        if (index == arr.size())    return 0;
        int ret = 0;
        for (int i = 0; arr[index] * i <= aim; i++)
        {
            ret += foo(arr, index + 1, aim - arr[index] * i);
        }
        return ret;
    }
};
// 记忆化搜索法
class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        if (n == 0 || aim == 0) return 0;
        unordered_map <string, int> mp;
        return foo(penny, 0, aim, mp);
    }
    int foo(const vector<int>& arr, int index, int aim, unordered_map<string, int>& mp)
    {
        if (aim == 0)   return 1;
        if (index == arr.size())    return 0;   // 此时 aim != 0
        string s = to_string(index) + " " + to_string(aim);
        if (mp.find(s) != mp.end())  return mp[s];
        else 
        {
            int ret = 0;
            for (int i = 0; arr[index] * i <= aim; i++)
            {
                ret += foo(arr, index + 1, aim - arr[index] * i, mp);
            }
            mp[s] = ret;
            return ret;
        }
    }
};
// 由记忆化搜索引出的 动态规划
class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        if (n == 0 || aim == 0)     return 0;
        int dp[n][aim+1];
        for (int i = 0; i < n; i++)    dp[i][0] = 1;
        for (int i = 1; i <= aim; i++)
        {
            if (i % penny[0] == 0)  dp[0][i] = 1;
            else                    dp[0][i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= aim; j++)
            {
                int count = 0;
                for (int k = 0; penny[i]*k <= j; k++)
                    count += dp[i-1][j-penny[i]*k];
                dp[i][j] = count;
            }
        }
        return dp[n-1][aim];
    }
};
// 优化过后的动态规划
class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        if (n == 0 || aim == 0)     return 0;
        int dp[n][aim+1];
        for (int i = 0; i < n; i++)     dp[i][0] = 1;
        for (int i = 1; i <= aim; i++) 
        {
            if (i % penny[0] == 0)      dp[0][i] = 1;
            else                        dp[0][i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= aim; j++)
            {
                if (j < penny[i])   dp[i][j] = dp[i-1][j];
                else                dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
            }
        }
        return dp[n-1][aim];
    }
};