/*
编写一个类,只能用两个栈结构实现队列,支持队列的基本操作(push，pop)
给定一个操作序列ope及它的长度n，其中元素为正数代表push操作，为0代表pop操作，保证操作序列合法且一定含pop操作，请返回pop的结果序列。
测试样例：
[1,2,3,0,4,0],6
返回：[1,2]
*/
#include <stack>
#include <vector>
using namespace std;

class TwoStack {
public:
    vector<int> twoStack(vector<int> ope, int n) {
        if (n < 0)   return vector<int>();
        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            if (ope[i] == 0 && s1.empty() && s2.empty())   return ret;
            else if (ope[i] == 0)   ret.push_back(pop());
            else    push(ope[i]);
        }
        return ret;
    }
    void push(int val)
    {
        while (!s2.empty()) 
        {
             s1.push(s2.top());
             s2.pop();
        }
        s1.push(val);
    }   
    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }
private:
    stack<int> s1;
    stack<int> s2;
};