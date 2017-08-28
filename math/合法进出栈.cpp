/*
    卡特兰数问题

n个数进出栈的顺序有多少种？假设栈的容量无限大。

给定一个整数n，请返回所求的进出栈顺序个数。保证结果在int范围内。
测试样例：

1

返回：1

*/

class Stack {
public:
    int countWays(int n) {
        int ret = 1;
        for (int i = n+1; i <= 2*n; i++)    ret *= i;
        for (int i = 1; i <= n; i++)        ret /= i;
        return ret / (n+1);
    }
};