// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
//
// 示例 1：
// 输入：s = "(()"
// 输出：2
// 解释：最长有效括号子串是 "()"
// 
// 示例 2：
//
// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"


// 解法一：
// dp[i]:包含s[i]的最长括号的长度
// s[i] == '('：dp[i] = 0
// s[i] == ')' && s[i - 1] == '(' : dp[i] = dp[i - 2] + 2;
// s[i] == ')' && s[i - 1] == ')' && s[i - 1 - dp[i - 1]] == '(': dp[i] = dp[i - 1] + 2 (s[i - 1 - dp[i - 1], i - 1] 这段的长度) + dp[i - 2 - dp[i - 1]]

// 解法二：
// 栈
// 入栈 ： ‘(’ || 栈空了
// 出栈 ： ')'
// 长度 ： i - stk.top()
// 初始化 ： stk.push(-1) -> ()
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        int maxAns = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (i > 0 && s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;

                } else if (i > 0 && s[i - 1] == ')') {
                    if (i - 1 - dp[i - 1] >=0 && s[i - 1 - dp[i - 1]] == '(') {
                        dp[i] = dp[i - 1] + ((i - 2 - dp[i - 1]) >= 0 ? dp[i - 2 - dp[i - 1]] : 0) + 2;
                    }
                }
                maxAns = max(maxAns, dp[i]);
            }
        }
        return  maxAns;

    }
    int longestValidParentheses_2(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        stack<int> stk;
        stk.push(-1);
        int maxAns = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i); 
            } else {
                stk.pop();
                if (st.empty()) {
                    stk.push(i);
                } else {
                    maxAns = max(maxAns, i - stk.top());
                }
            }
        }
        return maxAns;
    }
};