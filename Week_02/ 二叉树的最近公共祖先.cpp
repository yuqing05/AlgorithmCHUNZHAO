/*
 * @Description: 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * @FilePath: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        return root;

        
    }
};