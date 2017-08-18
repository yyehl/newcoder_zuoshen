/*
请用递归方式实现二叉树的先序、中序和后序的遍历打印。
给定一个二叉树的根结点root，请依次返回二叉树的先序，中序和后续遍历(二维数组的形式)。
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

class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) {
        vector<vector<int>> res(3, vector<int>());
         first_order(root, res[0]);
         mid_order(root, res[1]);
         last_order(root, res[2]);
        return res;
    }
    void first_order(TreeNode* root, vector<int>& v)
    {
        if (!root) return ;
        v.push_back(root->val);
        first_order(root->left, v);
        first_order(root->right, v);
    }
    void mid_order(TreeNode* root, vector<int>& v)
    {
        if (!root)  return;
        mid_order(root->left, v);
        v.push_back(root->val);
        mid_order(root->right, v);
    }
    void last_order(TreeNode* root, vector<int>& v)
    {
        if (!root) return ;
        last_order(root->left, v);
        last_order(root->right, v);
        v.push_back(root->val);
    }
};