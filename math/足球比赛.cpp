/*
有2k只球队，有k-1个强队，其余都是弱队，随机把它们分成k组比赛，每组两个队，问两强相遇的概率是多大？

给定一个数k，请返回一个数组，其中有两个元素，分别为最终结果的分子和分母，请化成最简分数
测试样例：

4

返回：[3,7]

*/

class Championship {
public:
    vector<int> calc(int k) {
        vector<int> ret(2);
        int m = 1, n = 1;
        for (int i = 1; i <= k + 1; i++)    m *= i;
        m = m/2;
        for (int i = 2*k - 1; i >= 1; i -= 2)   n *= i;
        m = n-m;
        ret = foo(m, n);
        return ret;
    }
    vector<int> foo(int m, int n)    // 化简
    {
        if (m == n)     return vector<int> (2, 1);
        if (m == 0)     {   vector<int> ret(2); ret[0] = 0; ret[1] = 1; return ret;}
        int a = m, b = n;
        if (a > b)      {  int tmp = a; a = b; b = tmp; }
        while (b % a != 0)      // b > a
        {
            int tmp = b % a;
            b = a;
            a = tmp;
        }
        m = m / a;
        n = n / a;
        vector<int> ret(2);
        ret[0] = m, ret[1] = n;
        return ret;
    }
};