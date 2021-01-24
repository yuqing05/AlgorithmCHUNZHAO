/*
 * @Date: 2021-01-23 21:43:47
 * @LastEditTime: 2021-01-24 14:22:18
 * @LinkPath: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

#include <vector>
using namespace std;

// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 
// 给定数组 nums = [1,1,2], 
// 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
// 你不需要考虑数组中超出新长度后面的元素。
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return size;
        } 
        int lastNotDup = 0;
        for (auto i = 1; i < size; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[++lastNotDup] = nums[i];
            }
        }
        return lastNotDup + 1;
    }
};


/* vim: set ts=4 sw=4 sts=4 tw=100 */
