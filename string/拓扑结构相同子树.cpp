/*
对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。
给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。
*/
#include <string>
#include <iostream>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class IdenticalTree {                             // find是KMP，所以实现时间复杂度为O(m+n)
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        string sa, sb;
        pre_order_tra(A, sa);
        pre_order_tra(B, sb);
        if (sa.find(sb) < sa.size())   return true;
        return false; 
    }
    void pre_order_tra(TreeNode* root, string& str)
    {
        if (!root)
        {
            str = str + '#';
            return ;
        }
        else 
        {
            str = str + to_string(root->val);
            pre_order_tra(root->left, str);
            pre_order_tra(root->right, str);
        }
    }

};


