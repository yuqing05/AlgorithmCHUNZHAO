/*
 * @Date: 2021-01-23 21:46:23
 * @LastEditTime: 2021-01-24 14:22:27
 * @LinkPath: https://leetcode-cn.com/problems/group-anagrams/
 */

#include <unordered_map>
#include <vector>
using namespace std;

// 
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        for (auto str : strs) {
            auto strSort = str;
            sort(strSort.begin(), strSort.end());
            strMap[strSort].push_back(str);
        }
        vector<vector<string>> result;
        for (auto item : strMap) {
            result.push_back(item.second);
        }
        return result;
    }
};


/* vim: set ts=4 sw=4 sts=4 tw=100 */
