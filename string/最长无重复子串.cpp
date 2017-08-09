/*
对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。
给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，且长度小于等于500。
*/
class DistinctSubstring {
public:
    int longestSubstring(string A, int n) {
        vector<int> alpha(26, -2);
        int maxlen = 0, preidx = -1;
        for (int i = 0; i < n; i++)
        {
            if (alpha[A[i]-'a'] < preidx)
            {
                maxlen = max(i-preidx, maxlen);
            }
            else 
            {
                preidx = alpha[A[i]-'a'];
            }
            alpha[A[i]-'a'] = i;
        }
        return maxlen;
    }
};