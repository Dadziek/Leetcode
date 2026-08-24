class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        pref = []
        current_sum = 0

        for stone in stones:
            current_sum += stone
            pref.append(current_sum)

        diff = pref[-1]

        for i in range(len(pref)-2, 0, -1):
            diff = max(diff, pref[i] - diff)
        
        return diff