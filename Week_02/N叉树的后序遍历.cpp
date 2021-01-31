/*
 * @Description: 给定一个 N 叉树，返回其节点值的后序遍历。
 * @FilePath: https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
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

    vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        stack<pair<Node*, bool>> stk;
        stk.push({root, false});
        vector<int> ans;
        while (!stk.empty()) {
            Node* cur = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();
            if (visited) {
                ans.push_back(cur->val);
                continue;   
            }
            stk.push({cur, true});
            for (int i = cur->children.size() - 1; i >= 0 ; --i) {
                if (cur->children[i]) stk.push({cur->children[i], false});
            }
            
        }
        return ans;
    }
};


