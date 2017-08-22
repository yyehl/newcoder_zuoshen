/*
给定一个整型数组arr，其中有两个数出现了奇数次，其他的数都出现了偶数次，找到这两个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。

给定一个整形数组arr及它的大小n，请返回一个数组，其中两个元素为两个出现了奇数次的元素,请将他们按从小到大排列。
测试样例：

[1,2,4,4,2,1,3,5],8

返回：[3,5]

*/

class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        int tmp1 = 0;
        for (int i = 0; i < n; i++)
        {
            tmp1 = tmp1 ^ arr[i];
        }
        int flag = -1;
        for (int i = 0; i < 32; i++)
        {
            if (((tmp1 << i) >> 31) & 1)
            {
                flag = i;
                break;
            }
        }
        int tmp2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (((arr[i] << flag) >> 31) & 1)
            {
                tmp2 = tmp2 ^ arr[i];
            }
        }
        int res1 = tmp2;
        int res2 = tmp2 ^ tmp1;
        vector<int> res;
        res.push_back(res1 < res2 ? res1 : res2);
        res.push_back(res1 < res2 ? res2 : res1);
        return res;
    }
};