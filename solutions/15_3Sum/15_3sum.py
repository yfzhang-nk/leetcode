class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for idx in range(len(nums)-2):
            if idx > 0 and nums[idx] == nums[idx-1]:
                continue
            left, right = idx+1, len(nums)-1
            while left < right:
                target = nums[idx] + nums[left] + nums[right]
                if target == 0:
                    res.append((nums[idx], nums[left], nums[right]))
                    while left < right and nums[left] == nums[left+1]:
                        left+=1
                    while left < right and nums[right] == nums[right-1]:
                        right -=1
                    left+=1
                    right-=1
                elif target < 0:
                    left += 1
                else:
                    right -= 1
        return res
            
