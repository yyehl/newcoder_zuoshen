/*
定义栈的数据结构，请在该类型中实现一个能够O(1)得到栈最小元素的min函数。 
*/
class Solution {
public:
    void push(int value) {
        if (s1.empty())
        {
            s1.push(value);
            s2.push(value);
        }
        else 
        {
            s1.push(value);
            value = value <= s2.top() ? value : s2.top();
            s2.push(value);
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top()
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};