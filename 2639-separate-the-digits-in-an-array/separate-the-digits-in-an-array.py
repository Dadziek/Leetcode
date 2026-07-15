class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        lst = []
            
        for i in nums:
            if i >= 10:
                temp = []
                while i > 0:
                    temp.insert(0, i % 10)
                    i //= 10
                lst.extend(temp)
            else:
                lst.append(i)
            
        return lst
    