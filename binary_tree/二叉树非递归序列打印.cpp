/*
请用非递归方式实现二叉树的先序、中序和后序的遍历打印。
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
        if (!root)  return ;
        stack<TreeNode*> ss;
        ss.push(root);
        while (!ss.empty())
        {
            root = ss.top();
            v.push_back(root->val);
            ss.pop();
            if (root->right)  ss.push(root->right);
            if (root->left)   ss.push(root->left);
        }
    }
    void mid_order(TreeNode* root, vector<int>& v)
    {
        if (!root)  return ;
        stack<TreeNode*> ss;
        while (root)
        {
            ss.push(root);
            root = root->left;
        }
        while (!ss.empty())
        {
            root = ss.top();
            v.push_back(root->val);
            ss.pop();
            if (root->right)
            {
                root = root->right;
                while (root)
                {
                    ss.push(root);
                    root = root->left;
                }
            }
        }
    }
    void last_order(TreeNode* root, vector<int>& v)
    {
        if (!root)  return;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s2.push(root);
            s1.pop();
            if (root->left)  s1.push(root->left);
            if (root->right) s1.push(root->right);
        }
        while (!s2.empty())
        {
            root = s2.top();
            v.push_back(root->val);
            s2.pop();
        }
    }
};