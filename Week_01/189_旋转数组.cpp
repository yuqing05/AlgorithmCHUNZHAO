/*
 * @Author: zhouyuqing
 * @Date: 2021-01-23 21:43:28
 * @LastEditTime: 2021-01-24 14:21:46
 * @LinkPath:  https://leetcode-cn.com/problems/rotate-array/
 */

#include <vector>
using namespace std;

//
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
// 进阶：
//    尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//    你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
// 
// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]

// 1. 使用新数组来存储待旋转的数组
class Solution_1 {
public:
    void rotate(vector<int>& nums, int k) {  
        vector<int> temp(nums);
        int size = temp.size();
        for (auto i = 0; i < size; i++) {
            nums[(i + k) % size] = temp[i];
        } 
    }
};

// 2. [0, nums.size()) 逆序 [0, k) 逆序 [k, nums.size()) 逆序
class Solution_2 {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// 3.循环替换 类似数组以步长为k的循环移动，需要找到开始的位置
class Solution_3 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        int n = gcd(k, size);
        for (auto start = 0; start < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % size;
                swap(prev, nums[next]);
                current = next;
            } while (start != current);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
