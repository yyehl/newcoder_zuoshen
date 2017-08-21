/*
有一棵二叉树,请设计一个算法判断它是否是完全二叉树。

给定二叉树的根结点root，请返回一个bool值代表它是否为完全二叉树。树的结点个数小于等于500。
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

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        if (!root)      return true;
        bool is_leaf = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                root = q.front();
                q.pop();
                if (is_leaf && (root->left || root->right))    return false;
                if (!root->left && root->right)    return false;
                if (root->left && !root->right) 
                {
                    is_leaf = true;
                    q.push(root->left);
                }
                else if (!root->left && !root->right)   is_leaf = true;
                else 
                {
                    q.push(root->left);
                    q.push(root->right);
                }
            }
        }
        return true;   
    }
};

