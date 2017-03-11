/**
 * author: 一元硬币
 * date: 2017-03-11
 * problem: 172. Factorial Trailing Zeroes
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n != 0) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};
