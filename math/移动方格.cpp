/*

在XxY的方格中，以左上角格子为起点，右下角格子为终点，每次只能向下走或者向右走，请问一共有多少种不同的走法

给定两个正整数int x,int y，请返回走法数目。保证x＋y小于等于12。
测试样例：

2,2

返回：2

*/
class Robot {
public:
    int countWays(int x, int y) {
        vector<vector<int>> v(x+1, vector<int>(y+1, 0));
        v[1][1] = 1;
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                v[i][j] = v[i][j] + v[i-1][j] + v[i][j-1];
            }
        }
        return v[x][y];
    }
};