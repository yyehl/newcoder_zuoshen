/*
n颗相同的糖果，分给m个人，每人至少一颗，问有多少种分法。

给定n和m，请返回方案数，保证n小于等于12，且m小于等于n。
测试样例：

10,3

返回：36

*/

class Distribution {
public:
    int getWays(int n, int m) {
        int ret = 1;
        for (int i = n-1; i >= n-m+1; i--)
            ret *= i;
        for (int i = 1; i <= m-1; i++)
            ret /= i;
        return ret;
    }
};