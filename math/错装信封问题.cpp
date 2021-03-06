/*


有n个信封，包含n封信，现在把信拿出来，再装回去，要求每封信不能装回它原来的信封，问有多少种装法?

给定一个整数n，请返回装发个数，为了防止溢出，请返回结果Mod 1000000007的值。保证n的大小小于等于300。
测试样例：

2

返回：1

分析： 递归思想
    当把A信封的信塞B信封之后，正好B信封的信也在A信封，那么 （n-1)*f(n-2)
    当把A信塞的信进B信封之后，B信封的信不在A信封中，那就相当于把B的信放到A的信封，重新计算这个问题  (n-1)f(n-1)
    因为可能会存在重复计算的问题，所以需要减去第一种情况

    递推式为： f(n) = (n-1)(f(n-1) - f(n-2));

*/

class CombineByMistake {
public:
    int countWays(int n) {
        if (n < 2)  return 0;
        if (n == 2) return 1;
        vector<long long> dp(3, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i%3] = (i-1) * (dp[(i-1)%3] + dp[(i-2)%3]);
            if (dp[i] > 1000000007)     dp[i] %= 1000000007;
        }
        return dp[n%3];
    }
};