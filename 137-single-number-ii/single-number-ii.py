class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        my_dict = {}

        for i in range(len(nums)):
            try:
                my_dict[nums[i]] += 1
            except KeyError:
                my_dict[nums[i]] = 1
        
        for key, val in my_dict.items():
            if val == 1:
                return key
        return -1
        