/**
 * author: 一元硬币
 * date: 2017-03-15
 * problem: 74. Search a 2D Matrix 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int base_i = 0, base_j = m - 1;
        while (base_i < n && base_j >= 0) {
            if (matrix[base_i][base_j] == target) {
                return true;
            } else if (matrix[base_i][base_j] < target) {
                base_i++;
            } else {
                base_j--;
            }
        }
        return false;
    }
};
