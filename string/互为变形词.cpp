/*
对于两个字符串A和B，如果A和B中出现的字符种类相同且每种字符出现的次数相同，则A和B互为变形词，
请设计一个高效算法，检查两给定串是否互为变形词。
给定两个字符串A和B及他们的长度，请返回一个bool值，代表他们是否互为变形词。
*/
class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        int arra[256], arrb[256];
        for (int i = 0; i < 256; i++)
            arra[i] = 0, arrb[i] = 0;
        for (int i = 0; i < lena; i++)
            arra[A[i]]++;
        for (int i = 0; i < lenb; i++)
            arrb[B[i]]++;
        for (int i = 0; i < 256; i++)
        {
            if (arra[i] != arrb[i])
                return false;
        }
        return true;
    }
};