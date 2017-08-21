/*
从二叉树的节点A出发，可以向上或者向下走，但沿途的节点只能经过一次，当到达节点B时，路径上的节点数叫作A到B的距离。
对于给定的一棵二叉树，求整棵树上节点间的最大距离。

给定一个二叉树的头结点root，请返回最大距离。保证点数大于等于2小于等于500.

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

class LongestDistance {
public:
    int findLongest(TreeNode* root) {
        longest = 0;
        int depth = find_dist(root);
        return longest;
    }
    int find_dist(TreeNode* root)
    {
        if (!root)  return 0;
        int ld = find_dist(root->left);
        int rd = find_dist(root->right);
        longest = max(longest, ld + rd + 1)；
        return max(ld, rd) + 1;
    }
private:
    int longest;
};