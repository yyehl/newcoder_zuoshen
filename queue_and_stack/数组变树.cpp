/*
对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，
MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对于MaxTree的每棵子树，
它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，
其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，
那么它就是树根。请设计O(n)的算法实现这个方法。
给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，
若为根则值为-1。
测试样例：
[3,1,4,2],4
返回：[2,0,-1,2]
*/

// 示例通过，牛客网的没通过，不知道为什么。。

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        if (n < 0)  return vector<int>();
        vector<int> left_max;
        vector<int> right_max;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && A[i] > A[s.top()])
                s.pop();
            if (s.empty())
                left_max.push_back(-1);
            else 
                left_max.push_back(s.top());
            s.push(i);
        }

        cout << "left_max: ";
        for (auto i : left_max)    cout << i << " ";  cout << endl;

        while (!s.empty())  s.pop();
        for (int i = n-1; i >= 0; i--)
        {
            while (!s.empty() && A[i] > A[s.top()])
                s.pop();
            if (s.empty())
                right_max.insert(right_max.begin(), -1);
            else 
                right_max.insert(right_max.begin(), s.top());
            s.push(i);
        }

        cout << "right_max: ";
        for (auto i : right_max)    cout << i << " ";  cout << endl;

        vector<int> res(n, -2);
        foo(A, res, left_max, right_max, 0);
        return res;    
    }
    void foo(const vector<int>& arr, vector<int>& res, const vector<int>& left_max, const vector<int>& right_max, int i)
    {
        while (i < arr.size())
        {
            if (left_max[i] == -1 && right_max[i] == -1)
                res[i] = -1;
            else if (left_max[i] == -1)
                res[i] = right_max[i];
            else if (right_max[i] == -1)
                res[i] = left_max[i];
            else 
                res[i] = left_max[i] > right_max[i] ? right_max[i] : left_max[i];
            i++;
        }
    }
};

int main()
{
    vector<int> v = {340,1387,2101,847,1660,733,36,528};
    MaxTree mm;
    vector<int> ret = mm.buildMaxTree(v, 8);
    for (auto i : ret)  cout << i << " "; cout << endl;
    return 0;
}