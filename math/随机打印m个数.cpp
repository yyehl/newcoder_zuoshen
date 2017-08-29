/*
给定一个长度为N且没有重复元素的数组arr和一个整数M，实现函数等概率随机打印arr中的M个数。
*/

class RandomPrint {
public:
    vector<int> print(vector<int> arr, int N, int M) {
        vector<int> ret;
        while (M--)
        {
            int index = rand() % N;
            ret.push_back(arr[index]);
            swap(arr[index], arr[N-1]);
            N--;
        }
        return ret;
    }
};