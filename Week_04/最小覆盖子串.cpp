/*
 * @Author: your name
 * @Date: 2021-02-20 11:17:56
 * @LastEditTime: 2021-02-21 23:45:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Week_04/最小覆盖子串.cpp
 */
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
// 示例 1：
// 
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

// 滑动窗口
// right 移动的时机：没找全子串
// left  移动的时机：找全子串

class Solution {
public:
    
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for (auto ch : t) {
            mp[ch]++;
        }
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;
        int hitCount = t.length();

        while (right < s.length()) {
            if (mp[s[right++]]-- > 0) {
                hitCount--;
            }
            while (hitCount == 0) {
                if (minLen > right - left) {
                    minLen = right - left;
                    start = left;
                }
                // 移动left
                if (mp[s[left++]]++ == 0) {
                    hitCount++;
                }
            } 

        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);

    }
};