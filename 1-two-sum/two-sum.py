class Solution(object):
    def twoSum(self, nums, target):
        m = {}
        for i, x in enumerate(nums):
            y = target - x
            if y in m:
                return [m[y], i]
            m[x] = i