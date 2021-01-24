/*
 * @Date: 2021-01-23 21:45:09
 * @LastEditTime: 2021-01-24 17:04:03
 * @LinkPath: https://leetcode-cn.com/problems/valid-anagram/description/
 */

#include <unordered_map>
using namespace std;

//
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 输入: s = "anagram", t = "nagaram"
// 输出: true
//
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]]++;
            charMap[t[i]]--;
        }
        for (auto item : charMap) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
