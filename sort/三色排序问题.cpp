/*
有一个只由0，1，2三种元素构成的整数数组，请使用交换、原地排序而不是使用计数进行排序。

给定一个只含0，1，2的整数数组A及它的大小，请返回排序后的数组。保证数组大小小于等于500。
*/
#include <vector>
#include <iostream>
using namespace std;

class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> A, int n) {
        int left = 0, right = n, i = 0;
        while (i < right)
        {
            if (A[i] == 1)  
                ++i;
            else if (A[i] == 2) 
                swap(A[i], A[--right]);
            else
            {
                swap(A[i], A[++left]);
                if (i == left)  ++i;
            }
        }
        return A;
    }
};
int main()
{
    vector<int> v = {1,2,1,0,0,1,2};
    ThreeColor tt;
    vector<int> ret = tt.sortThreeColor(v, v.size());
    for (auto i : ret)  cout << i << " ";  cout << endl;
    return 0;
}