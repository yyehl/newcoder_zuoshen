/*
现在有一个行和列都排好序的矩阵，请设计一个高效算法，快速查找矩阵中是否含有值x。
给定一个int矩阵mat，同时给定矩阵大小nxm及待查找的数x，
请返回一个bool值，代表矩阵中是否存在x。所有矩阵中数字及x均为int范围内整数。
保证n和m均小于等于1000。   rows   colums
*/

#include <vector>
#include <iostream>
using namespace std;

class Finder {
public:
    bool findX(vector<vector<int> > mat, int n, int m, int x) {
        int row = 0, colum = m-1;
        while (row < n && colum >= 0)
        {
            if (mat[row][colum] == x)   return true;
            else if (mat[row][colum] > x)    colum--;
            else if (mat[row][colum] < x)   row++;
        } 
        return false;
    }
};
int main()
{
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    cout << mat.size() << " " << mat[0].size() << endl;
    int m = 4, n = 3;
    Finder ff;
    cout << ff.findX(mat, m, n, 12) << endl;
    return 0;
}