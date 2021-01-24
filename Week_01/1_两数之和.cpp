/*
 * @Author: zhouyuqing
 * @Date: 2021-01-23 21:43:47
 * @LastEditTime: 2021-01-24 14:21:17
 * @LinkPath: https://leetcode-cn.com/problems/two-sum/
 */

#include <vector>
#include <unordered_map>
using namespace std;

//
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
// 
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
// 你可以按任意顺序返回答案。
//
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1]
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  numMap;
        for (auto i = 0; i < nums.size(); i++) {
            auto it = numMap.find(target - nums[i]);
            if (it != numMap.end()) {
                return {it->second, i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};




/* vim: set ts=4 sw=4 sts=4 tw=100 */
