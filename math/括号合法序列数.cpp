/*
卡特兰数问题


假设有n对左右括号，请求出合法的排列有多少个？合法是指每一个括号都可以找到与之配对的括号，比如n=1时，()是合法的，但是)(为不合法。

给定一个整数n，请返回所求的合法排列数。保证结果在int范围内。
测试样例：

1

返回：1

*/

class Parenthesis {
public:
    int countLegalWays(int n) {
        int c2nn1 = 1;
        for (int i = 2*n; i > n; i--)    c2nn1 *= i;
        for (int i = 1; i <= n; i++)    c2nn1 /= i;
        return c2nn1/(n+1);
    }
};