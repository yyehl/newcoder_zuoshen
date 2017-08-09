/*
对于一个给定的字符串数组，请找到一种拼接顺序，使所有小字符串拼接成的大字符串是所有可能的拼接中字典序最小的。
给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。
*/

class Prior {
public:
    string findSmallest(vector<string> strs, int n) {
        if (n == 0)   return string();
        if (n == 1)   return strs[0];
        string ret;
        sort(strs.begin(), strs.end());
        for (int i = 0; i < n-1; i++)
        {
            if (strs[i]+strs[i+1] < strs[i+1]+strs[i])
            {
                ret += strs[i];
            }
            else if (strs[i]+strs[i+1] > strs[i+1]+strs[i])
            {
                swap(strs[i], strs[i+1]);
                ret += strs[i];
            }
            else 
            {
                int j = i;
                while (i < n-1 && strs[i] == strs[i+1])   i++;
                int k = i;
                if (i == n-1)
                {
                    while (j < n-1)   ret += strs[j++];
                    break;
                }
                if (strs[i]+strs[i+1] < strs[i+1]+strs[i])
                {
                    while (j <= i)  ret += strs[j++];
                }
                else 
                {
                    ret += strs[i+1];
                    i++;
                    while (i < n-1 && (strs[i+1]+strs[j] < strs[j]+strs[i+1]))
                    {
                        ret += strs[i+1];
                        i++;
                    }
                    while (j <= k)  ret = ret + strs[j++];
                    if (i == n-1)   return ret;
                }
            }
        }
        ret += strs[n-1];
        return ret;
    }
};

class Prior {
public:
    string findSmallest(vector<string> strs, int n) {
        if (n == 0) return string();
        if (n == 1) return strs[0];
        sort(strs.begin(), strs.end(), compare);
        string ret;
        for (int i = 0; i < n; i++)
            ret += strs[i];
        return ret;
    }
    bool compare(const string& str1, const string&  str2)
    {
        return str1 + str2 < str2 + str1 ? true : false;
    }
};

