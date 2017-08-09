/*
对于一个字符串，请设计一个算法，将字符串的长度为len的前缀平移到字符串的最后。
给定一个字符串A和它的长度，同时给定len，请返回平移后的字符串。
*/

class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        if (n <= 1 || len >= n || len < 0)   return A;
        reverse_string(A, 0, len-1);
        reverse_string(A, len, n-1);
        reverse_string(A, 0, n-1);
        return A;

    }
    void reverse_string(string& str, int left, int right)
    {
        for (int i = left; i <= left + (right-left)/2; i++)
            swap(str[i], str[right+left-i]);
    }
};