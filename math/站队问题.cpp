/*
n个人站队，他们的编号依次从1到n，要求编号为a的人必须在编号为b的人的左边，但不要求一定相邻，请问共有多少种排法？第二问如果要求a必须在b的左边，并且一定要相邻，请问一共有多少种排法？

给定人数n及两个人的编号a和b，请返回一个两个元素的数组，其中两个元素依次为两个问题的答案。保证人数小于等于10。
测试样例：

7,1,2

返回：[2520,720]

*/

class StandInLine {
public:
    vector<int> getWays(int n, int a, int b) {
        vector<int> ret(2, 0);
        ret[0] = foo1(n, a, b);
        ret[1] = foo2(n, a, b);
        return ret;
    }
    int foo1(int n, int a, int b)
    {
        int tmp = 1;
        for (int i = 1; i <= n-2; i++)
            tmp *= i;
        return n*(n-1)/2 * tmp;
    }
    int foo2(int n, int a, int b)
    {
        int tmp = n-1;
        for (int i = 1; i <= n-2; i++)
            tmp *= i;
        return tmp;
    }
};