class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return target
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for idx in range(len(nums) - 2):
            left = idx+1
            right = len(nums) - 1
            while left < right:
                sums = nums[idx] + nums[left] + nums[right]
                if sums == target:
                    return target
                if abs(sums-target) < abs(result-target):
                    result = sums
                if sums < target:
                    left += 1
                elif sums > target:
                    right -= 1
        return result
        
