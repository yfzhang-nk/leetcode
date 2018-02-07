/*
 * author: yfzhang
 * date: 2017-03-07
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> left;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (left.find(tmp) != left.end()) {
                ret.push_back(left[tmp]);
                ret.push_back(i);
                return ret;
            } else {
                left[nums[i]] = i;
            }
        }
        return ret;
    }
};
