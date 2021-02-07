
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(vector<string> &res, unordered_map<char, string>& book, string digits,  string& path, int level) {
        if (level == digits.size()) {
            res.push_back(path);
            return;
        }
        string letters = book[digits[level]];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            dfs(res, book, digits, path, level + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> book = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> res;
        string path;
        dfs(res, book, digits, path, 0);
        return res;
    }
};