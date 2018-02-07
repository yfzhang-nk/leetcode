/**
 * author: 一元硬币
 * date: 2017-03-08
 * problem: 264. Ugly Number II
 */ 
class Solution {
public:
    int nthUglyNumber(int n) {
        // write your code here
        int count = 1;
        vector<int> uglynum;
        uglynum.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (count < n) {
            int cur = min3(uglynum[i2]*2, uglynum[i3]*3, uglynum[i5]*5);
            uglynum.push_back(cur);
            if (cur == uglynum[i2]*2) i2 ++;
            if (cur == uglynum[i3]*3) i3 ++;
            if (cur == uglynum[i5]*5) i5 ++;
            count++;
        }
        return uglynum[uglynum.size()-1];
    }
    
    int min3(int a, int b, int c) {
        int d = min(a, b);
        return min(d, c);
    }
};
