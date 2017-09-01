/*
一个背包有一定的承重cap，有N件物品，每件都有自己的价值，记录在数组v中，也都有自己的重量，记录在数组w中，
每件物品只能选择要装入背包还是不装入背包，要求在不超过背包承重的前提下，选出物品的总价值最大。
给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。
测试样例：
[1,2,3],[1,2,3],3,6
返回：6
*/
// dp

class Backpack {
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
        if (cap == 0 || n == 0) return 0;
        int dp[n+1][cap+1];
        for (int i = 0; i <= n; i++)    dp[i][0] = 0;
        for (int j = 0; j <= cap; j++)  dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= cap; j++)
            {
                if (j < w[i-1])   dp[i][j] = dp[i-1][j];
                else  dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
        }
        return dp[n][cap];
    }
};