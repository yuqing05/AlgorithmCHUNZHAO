
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。
// 分治的方法 
// 1. x^n = x ^ (n/2)^2
// 2. 奇数和偶数
// 3. n 是负数


class Solution {
public:
    double helper(double x, long n) {
        if (n == 0) {
            return 1;
        }
        double res = helper(x, n / 2);
        return n % 2 == 1 ? res * res * x : res * res;
    }
    double myPow(double x, long n) {
        if (n < 0) {
             return helper(1/x, -n);
        }
        return helper(x, n);

    }
};
