/*
于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
*/
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == '(')   m++;
            else if (A[i] == ')')  m--;
            else    return false;
            if (m < 0)  return false;
        }
        if (m != 0)   return false;
        return true;
    }
};