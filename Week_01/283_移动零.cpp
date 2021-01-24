/*
 * @Date: 2021-01-23 21:44:05
 * @LastEditTime: 2021-01-24 14:21:58
 * @LinkPath: https://leetcode-cn.com/problems/move-zeroes/
 */

#include <vector>
using namespace std;

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 示例:
//
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]
//
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNotZero = -1;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                swap(nums[i], nums[++lastNotZero]);
            }
        }    
    }
};



/* vim: set ts=4 sw=4 sts=4 tw=100 */
