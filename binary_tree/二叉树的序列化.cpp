/*
首先我们介绍二叉树先序序列化的方式，假设序列化的结果字符串为str，初始时str等于空字符串。
先序遍历二叉树，如果遇到空节点，就在str的末尾加上“#!”，“#”表示这个节点为空，节点值不存在，
当然你也可以用其他的特殊字符，“!”表示一个值的结束。如果遇到不为空的节点，假设节点值为3，就在str的末尾加上“3!”。
现在请你实现树的先序序列化。

给定树的根结点root，请返回二叉树序列化后的字符串。
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

class TreeToString {
public:
    string toString(TreeNode* root) {
        string res;
        to_string(root, res);
        return res;
    }
    void tree_to_string(TreeNode* root, string& res)
    {
        if (!root)  
        {
            res += '#';
            return ;
        }
        res += to_string(root->val);
        res += '!';
        tree_to_string(root->left, res);
        tree_to_string(root->right, res);
    }
};