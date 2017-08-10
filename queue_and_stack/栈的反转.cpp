/*
实现一个栈的逆序，但是只能用递归函数和这个栈本身的pop操作来实现，而不能自己申请另外的数据结构。
给定一个整数数组A即为给定的栈，同时给定它的大小n，请返回逆序后的栈。
测试样例：
[4,3,2,1],4
返回：[1,2,3,4]
*/
#include <vector>
#include <stack>
using namespace std;

class StackReverse {
public:
    vector<int> reverseStack(vector<int> A, int n) {
        if (n <= 1) return A;
        foo(A);
        return A;
    }
    int get_bottom(vector<int>& s)
    {
        int x = s.back();
        s.pop_back();
        if (s.empty())  return x;
        int ret = get_bottom(s);
        s.push_back(x);
        return ret;
    }
    void foo(vector<int>& s)
    {
        if (s.empty())  return ;
        int x = get_bottom(s);
        foo(s);
        s.push_back(x);
    }
};