/*
 * @Author: zhouyuqing
 * @Date: 2021-01-23 21:44:33
 * @LastEditTime: 2021-01-24 14:21:34
 * @FilePath: https://leetcode-cn.com/problems/plus-one/
 */

#include <vector>
using namespace std;

//
// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 
// 你可以假设除了整数 0 之外，这个整数不会以零开头。
// 输入：digits = [1,2,3]
// 输出：[1,2,4]
// 解释：输入数组表示数字 123。
//
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (flag == 0) {
                return digits;
            }
            int sum = digits[i] + flag;
            flag = sum / 10;
            digits[i] = sum % 10;
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
