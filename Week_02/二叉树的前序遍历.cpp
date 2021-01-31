/*
 * @Description: 给定一个二叉树的根节点 root ，返回它的 前序 遍历。
 * @FilePath: https://leetcode-cn.com/problems/binary-tree-preorder-traversal
 */

/**
 * Definition for a binary tree node.
 **/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            if (cur->right) {stk.push(cur->right);}
            if (cur->left) {stk.push(cur->left);}
        }
        return result;

    }
};