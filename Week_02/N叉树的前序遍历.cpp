/*
 * @Description: 给定一个 N 叉树，返回其节点值的前序遍历。
 * @FilePath: https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
 */


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        stack<Node*> stk;
        vector<int> result;

        stk.push(root);

        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            result.push_back(cur->val);

            for (int i = cur->children.size() - 1; i >= 0; --i) {
                stk.push(cur->children[i]);
            }
        }
        return result;   
    }
};