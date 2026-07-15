class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        tab = []
        for i in range(len(candies)):
            cond = True
            for j in range(len(candies)):
                if candies[i] + extraCandies < candies[j]:
                    cond = False
                    break
            tab.append(cond)
        return tab