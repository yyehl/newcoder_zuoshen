/*
请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，
并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
*/

class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        if (length <= 0)    return iniString;
        int count = 0;
        for (int i = 0; i < iniString.size(); i++)
        {
            if (iniString[i] == ' ')    count++;
        }
        int append_len = iniString.size() + 2*count;
        string ret(append_len, ' ');
        int i = append_len-1, j = iniString.size()-1;
        while (i >= 0 && j >= 0)
        {
            if (iniString[j] == ' ')
            {
                ret[i] = '0';
                ret[--i] = '2';
                ret[--i] = '%';
            }
            else 
                ret[i] = iniString[j];
            --i, --j;
        }
        return ret;
    }
};