/*
卡特兰数的第二个定理：
当fn满足，f0 = 1, f1 = 1, f2 = 2, f3 = 5...
且 fn = f0 * fn-1 + f1 * fn-2 + f2 * fn-3 ......+ fn-2 * f1 + fn-1 * f0
则 fn = C(2n, n) - C(2n, n-1) = (1 / (n-1)) * C(2n, n)

卡特兰数的第二个重要定理，记住～！



求n个无差别的节点构成的二叉树有多少种不同的结构？

给定一个整数n，请返回不同结构的二叉树的个数。保证结果在int范围内。
测试样例：

1

返回：1

*/

class TreeCount {
public:
    int countWays(int n) {
        int ret = 1; 
        for (int i = n+1; i <= 2*n; i++)    ret *= i;
        for (int i = 1; i <= n; i++)        ret /= i;
        return ret / (n+1);
    }
};