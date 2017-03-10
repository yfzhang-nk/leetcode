/**
 * author: 一元硬币
 * date: 2017-03-09
 * problem: 313. Super Ugly Number
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        int size = primes.size();
        if (size == 0) return 0;
        vector<int> superugly;
        vector<int> primeIdx(size, 0);
        superugly.push_back(1);
        int count = 1;
        while (count < n) {
            superugly.push_back(minx(superugly, primeIdx, primes));
            count++;
        }
        return superugly[n-1];
    }
    
    int minx(vector<int>& ugly, vector<int> &idx, vector<int> &primes) {
        int minNum = INT_MAX;
        for (int i = 0; i < idx.size(); ++i) {
            int cur = primes[i] * ugly[idx[i]];
            if (minNum > cur) {
                minNum = cur;
            }
        }
        for (int i = 0; i < idx.size(); ++i) {
            if (minNum == primes[i]*ugly[idx[i]]) {
                idx[i] ++;
            }
        }
        return minNum;
    }
};
