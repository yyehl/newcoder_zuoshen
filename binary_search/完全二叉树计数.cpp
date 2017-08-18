/*
给定一棵完全二叉树的根节点root，返回这棵树的节点个数。
如果完全二叉树的节点数为N，请实现时间复杂度低于O(N)的解法。
给定树的根结点root，请返回树的大小。
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

class CountNodes {
public:
    int count(TreeNode* root) {
        if (!root)  return 0;
        return fooo(root, 0);
    }
    int fooo(TreeNode* root, int count)
    {
        int h = 0;
        TreeNode* p = root;
        while (p)
        {
            h++;
            p = p->left;
        }

        if (h == 1)  return count + 1;

        TreeNode* p1 = root->right;
        int rh = 1;
        while (p1)
        {
            rh++;
            p1 = p1->left;
        }
        if (rh == h)
        {
            int rc = pow(2, h-1);
            return fooo(root->right, rc + count);
        }
        else 
        {
            int rc = pow(2, rh-1);
            return fooo(root->left, rc + count);
        }
    }
};