/*
对于一个字符串，请设计一个算法，只在字符串的单词间做逆序调整，
也就是说，字符串由一些由空格分隔的部分组成，你需要将这些部分逆序。
给定一个原字符串A和他的长度，请返回逆序后的字符串。
*/
class Reverse {
public:
    string reverseSentence(string A, int n) {
        reverse_substring(A, 0, n-1);
        int left = 0, right = 0;
        for (int i = 0; i < n; )
        {
            while (i < n && A[i] == ' ')
            {
                i++;
                left++;
            }
            right = left;
            while (i < n && A[i] != ' ')
            {
                i++;
                right++;
            }
            reverse_substring(A, left, right-1);
            left = right;
        }
        return A;
    }
    void reverse_substring(string& A, int left, int right)
    {
        while (left < right)
        {
            swap(A[left++], A[right--]);
        }
    }
};