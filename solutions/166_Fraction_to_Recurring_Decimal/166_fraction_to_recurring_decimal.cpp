/**
 * author: 一元硬币
 * date: 2017-03-10
 * problem: 166. Fraction to Recurring Decimal
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long n = abs(long(numerator)), d = abs(long(denominator));
        string ret;
        if ( (numerator<0 && denominator>0) || (numerator>0 && denominator<0) ) ret = '-';
        ret += to_string(n/d);
        if (n%d == 0) return ret;
        unordered_map<long, int> idx;
        ret += '.';
        for (long r=n%d; r ; r%=d) {
            if (idx.find(r) != idx.end()) {
                ret.insert(idx[r], 1, '(');
                ret += ')';
                return ret;
            }
            idx[r] = ret.size();
            r *= 10;
            ret += to_string(r/d);
        }
        return ret;
    }
};
