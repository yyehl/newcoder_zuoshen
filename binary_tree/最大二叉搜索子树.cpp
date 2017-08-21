/*
有一棵二叉树，其中所有节点的值都不一样,找到含有节点最多 的搜索二叉子树,并返回这棵子树的头节点.

给定二叉树的头结点root，请返回所求的头结点,若出现多个节点最多的子树，返回头结点权值最大的。

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
class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
        if (!root)      return NULL;
        int minv, maxv, maxn;
        return fooo(root, minv, maxv, maxn);
    }
    TreeNode* fooo(TreeNode* root, int& minv, int& maxv, int& maxn)
    {
        if (!root)  
        {
            minv = INT_MAX;
            maxv = INT_MIN;
            maxn = 0;
            return NULL;
        }
        int lmin, lmax, lnum;
        TreeNode* lnode = fooo(root->left, lmin, lmax, lnum);

        int rmin, rmax, rnum;
        TreeNode* rnode = fooo(root->right, rmin, rmax, rnum);

        minv = min(root->val, lmin);
        maxv = max(root->val, rmax);

        if (root->val > lmax && root->val < rmin && lnode == root->left && rnode == root->right)
        {
            maxn = lnum + rnum + 1;
            return root;
        }

        if (lnum > rnum)    
        {
            maxn = lnum;
            return lnode;
        }
        else 
        {
            maxn = rnum;
            return rnode;
        }
    }
};