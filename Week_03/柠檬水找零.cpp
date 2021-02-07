/*
 * @Author: your name
 * @Date: 2021-02-07 17:04:39
 * @LastEditTime: 2021-02-07 22:13:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Week_03/柠檬水找零.cpp
 */

// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
//
// 顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
// 注意，一开始你手头没有任何零钱。
//
// 如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;

        for (auto bill : bills) {
            if (bill == 5) {
                fiveCount++;
            } else if (bill == 10) {
                tenCount++;
                fiveCount--;
            } else if (tenCount > 0) {
                tenCount--;
                fiveCount--;
            } else {
                fiveCount -= 3;
            }
            if (fiveCount < 0) {
                return false;
            }
        return true;
        
    }
};