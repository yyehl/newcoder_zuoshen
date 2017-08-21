/*

有一棵二叉树，请设计一个算法判断这棵二叉树是否为平衡二叉树。

给定二叉树的根结点root，请返回一个bool值，代表这棵树是否为平衡二叉树。

*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    bool check(TreeNode* root) {
        if (!root)   return true;
        return get_high(root) > 0 ? true : false;
    }
    int get_high(TreeNode* root)
    {
        if (!root)  return 0;
        int lh = get_high(root->left);
        int rh = get_high(root->right);
        if (lh < 0 || rh < 0 || abs(lh - rh) > 1)   return -1;
        else 
            return max(lh, rh)  + 1;
    }
};