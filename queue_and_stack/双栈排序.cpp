/*
请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），
要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。
请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]
*/
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        if (numbers.empty())    return numbers;
        
        tmp.push(numbers.back());
        numbers.pop_back();
        while (!numbers.empty())
        {
            int num = numbers.back();
            numbers.pop_back();
            while (!tmp.empty() && num < tmp.top())
            {
                numbers.push_back(tmp.top());
                tmp.pop();
            }
            tmp.push(num);
            while (!numbers.empty() && numbers.back() >= tmp.top())
            {
                tmp.push(numbers.back());
                numbers.pop_back();
            }
        }
        while (!tmp.empty())
        {
            numbers.push_back(tmp.top());
            tmp.pop();
        }
        return numbers;
    }
    private:
    stack<int> tmp;
};