/*

请把纸条竖着放在桌⼦上，然后从纸条的下边向上⽅对折，压出折痕后再展 开。
此时有1条折痕，突起的⽅向指向纸条的背⾯，这条折痕叫做“下”折痕 ；突起的⽅向指向纸条正⾯的折痕叫做“上”折痕。
如果每次都从下边向上⽅ 对折，对折N次。请从上到下计算出所有折痕的⽅向。
给定折的次数n,请返回从上到下的折痕的数组，若为下折痕则对应元素为"down",若为上折痕则为"up".
测试样例：

1

返回：["down"]

*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) { }            // xia 1  shang 2
};

class FoldPaper {
public:
    vector<string> foldPaper(int n) {
        if (!n)     return vector<string>();
        TreeNode* root = new TreeNode(1);
        root = build_tree(root, n-1);
        vector<string> res;
        pre_print(root, res);
        return res;
    }
    TreeNode* build_tree(TreeNode* root, int n)
    {
        TreeNode* res = root;
        queue<TreeNode*> q;
        q.push(root);
        while (n--)
        {
            int sz = q.size();
            while (sz--)
            {
                root = q.front();
                q.pop();
                root->left = new TreeNode(1);
                root->right = new TreeNode(2);
                q.push(rot->left);
                q.push(root->right);
            }
        }
        return res;
    }
    void pre_print(TreeNode* root, vector<string>& res)
    {
        if (!root)  return ;
        pre_print(root->left, res);
        string s = root->val == 1 ? "down" : "up";
        res.push_back(s);
        pre_print(root->right, res);
    }
};