// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//   每行中的整数从左到右按升序排列。
//   每行的第一个整数大于前一行的最后一个整数。
// 示例：
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        } 
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int value = matrix[mid / n][mid % n];
            if (value == target) {
                return true;
            }
            if (value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

};