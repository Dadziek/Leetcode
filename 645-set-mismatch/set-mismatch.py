class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        
        duplicate = -1
        missing = 1
        
        for i in range(len(nums)):
            if i > 0:
                if nums[i] == nums[i - 1]:
                    duplicate = nums[i]
                elif nums[i] > nums[i - 1] + 1:
                    missing = nums[i - 1] + 1
                    
        if nums[-1] != len(nums):
            missing = len(nums)
            
        return [duplicate, missing]