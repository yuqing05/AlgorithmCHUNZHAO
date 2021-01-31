/*
 * @Description: 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
 * @FilePath: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        stack<pair<TreeNode*, bool>> stk;
        stk.push({root, false});

        while (!stk.empty()) {
            TreeNode* cur = stk.top().first;
            bool visited = stk.top().second;

            stk.pop();
            if (visited) {
                result.push_back(cur->val);
                continue;
            }

            if (cur->right) stk.push({cur->right, false});
            stk.push({cur, true});
            if (cur->left) stk.push({cur->left, false});
        }
        return result;

    }
};