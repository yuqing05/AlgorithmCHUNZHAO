/*
 * @Date: 2021-01-23 21:46:38
 * @LastEditTime: 2021-01-24 12:50:06
 * @LinkPath: https://leetcode.com/problems/trapping-rain-water/
 */

#include <vector>
#include <stack>
using namespace std;

//
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
//
// 解法关键点：有个凹槽才能承接雨水,所以左右边界都比要计算的位置高才行
// 1. 单调递减栈：遇到比栈顶元素大时才出栈， 比占顶元素小，入栈；
// 2. 左边边界法：max_left 是最大的左边界 它的取值范围是 [0,left],
// 则[0, left] 的雨水可以通过 max_left - height[left] 累加得到；
// 右侧类似

// 单调栈
class Solution_1 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int topHeight = height[stk.top()];
                stk.pop();
                if (stk.empty()) { // 没有左边界
                    break;
                }
                int width = i - stk.top() - 1;
                ans += (min(height[i], height[stk.top()]) - topHeight) * width;
            }
            stk.push(i);
        }
        return ans;        
    }
};
// 左右边界
class Solution_2 {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size < 2) {
            return 0;
        }      
        int left = 0;
        int right = size - 1;
        int max_left = height[left];
        int max_right = height[right];

        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                max_left = max(max_left, height[left]);
                ans += max_left - height[left];
                left++;
            } else {
                max_right = max(max_right, height[right]);
                ans += max_right - height[right];
                right--;
            }
        }
        return ans;
    }
};


/* vim: set ts=4 sw=4 sts=4 tw=100 */
