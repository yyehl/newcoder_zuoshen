/*
有一个矩阵map，它每个格子有一个权值。从左上角的格子开始每次只能向右或者向下走，最后到达右下角的位置，
路径上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。
给定一个矩阵map及它的行数n和列数m，请返回最小路径和。保证行列数均小于等于100.
测试样例：
[[1,2,3],[1,1,1]],2,3
返回：4
*/
// 暴力搜索法 
class MinimumPath {
public:
    int getMin(vector<vector<int> > map, int n, int m) {
        if (n <= 0 || m <= 0)   return 0;
        return foo(map, n-1, m-1);
    }
    int foo(const vector<vector<int>>& map, int i, int j)
    {
        if (i == 0 && j == 0)   return map[0][0];
        if (i == 0)             return map[i][j] + foo(map, i, j-1);
        if (j == 0)             return map[i][j] + foo(map, i-1, j);     
        return map[i][j] + min(foo(map, i-1, j), foo(map, i, j-1));  
    }
};
// 记忆化搜索法
#include <unordered_map>
class MinimumPath {
public:
    int getMin(vector<vector<int> > map, int n, int m) {
        if (n <= 0 || m <= 0)   return 0;
        unordered_map<string, int> dp;
        return foo(map, n-1, m-1, dp);
    }
    int foo(const vector<vector<int>>& map, int i, int j, unordered_map<string, int>& dp)
    {
        string s = to_string(i) + " " + to_string(j);
        if (dp.find(s) != dp.end())     return dp[s];
        if (i == 0 && j == 0)           return dp[s] = map[0][0];   
        if (i == 0)                     return dp[s] = map[i][j] + foo(map, i, j-1, dp);
        if (j == 0)                     return dp[s] = map[i][j] + foo(map, i-1, j, dp);
        return dp[s] = map[i][j] + min(foo(map, i-1, j, dp), foo(map, i, j-1, dp));
    }
};
// 动态规划
class MinimumPath {
public:
    int getMin(vector<vector<int> > map, int n, int m) {
        if (n <= 0 || m <= 0)   return 0;
        int dp[n][m];
        dp[0][0] = map[0][0];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i-1][0] + map[i][0];
        for (int i = 1; i < m; i++)
            dp[0][i] = dp[0][i-1] + map[0][i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + map[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};