/*
对于两个32位整数a和b，请设计一个算法返回a和b中较大的。但是不能用任何比较判断。若两数相同，返回任意一个。

给定两个整数a和b，请返回较大的数。
测试样例：

1,2

返回：2

*/

class Compare {
public:
    int getMax(int a, int b) {
        int c = a - b;
        int tmp1 = (c>>31)&1;   // 如果c大于0，则tmp1为0，若c小于0，则tmp1为1
        int tmp2 = tmp1 ^ 1;    // 
        return tmp1 * b + tmp2 * a;
    }
};