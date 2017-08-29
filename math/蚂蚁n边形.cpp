/*
n只蚂蚁从正n边形的n个定点沿着边移动，速度是相同的，问它们碰头的概率是多少？

给定一个正整数n，请返回一个数组，其中两个元素分别为结果的分子和分母，请化为最简分数。
测试样例：

3

返回：[3,4]

*/

class Ants {
public:
    vector<int> collision(int n) {
        vector<int> ret(2);
        int m = 1;
        for (int i = 0; i < n-1; i++)
            m *= 2;
        ret[1] = m;
        ret[0] = m-1;
        return ret;
    }
};