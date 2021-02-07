// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
// 示例 1：
// 
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
// 示例 2：
// 
// 输入：nums = [0]
// 输出：[[],[0]]
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> sub;
    void dfs(vector<int>& nums, int index) {
        result.push_back(sub);
        for (int i = index; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            dfs(nums, i + 1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;

    }
};