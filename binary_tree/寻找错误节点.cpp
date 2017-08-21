/*

一棵二叉树原本是搜索二叉树，但是其中有两个节点调换了位置，使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点并返回他们的值。
保证二叉树中结点的值各不相同。

给定一棵树的根结点，请返回两个调换了位置的值，其中小的值在前。

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

class FindErrorNode {
public:
    vector<int> findError(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> q;
        while (root)
        {
            q.push(root);
            root = root->left;
        }
        int pre_val, now_val;
        if (!q.empty())
        {
            root = q.top();
            q.pop();
            pre_val = root->val;       // 
            if (root->right)
            {
                root = root->right;
                q.push(root);
                while (root->left)
                {
                    q.push(root->left);
                    root = root->left;
                }
            }
        }
        while (!q.empty())
        {
            root = q.top();
            q.pop();
            now_val = root->val;
            if (pre_val > now_val)
            {
                res.push_back(pre_val);
                res.push_back(now_val);
            }
            if (root->right)
            {
                root = root->right;
                q.push(root);
                while (root->left)
                {
                    q.push(root->left);
                    root = root->left;
                }
            }
            pre_val = now_val;
        }
        if (res.size() == 2)
        {
            swap(res[0], res[1]);
        }
        if (res.size() == 4)
        {
            res.erase(res.begin()+1);
            res.erase(res.begin()+1);
            swap(res[0], res[1]);
        }
        return res;
    }
};