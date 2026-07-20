class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        my_dict = {}

        for i in range(len(nums)):
            try:
                my_dict[nums[i]] += 1
            except KeyError:
                my_dict[nums[i]] = 1
        
        tab = []
        for key, val in my_dict.items():
            if val == 1:
                tab.append(key)
                
        return tab