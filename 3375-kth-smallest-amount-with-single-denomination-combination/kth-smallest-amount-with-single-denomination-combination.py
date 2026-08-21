class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins = [c for c in coins if not any(c != o and c % o == 0 for o in coins)]
        
        subsets = []
        for r in range(1, len(coins) + 1):
            sign = 1 if r % 2 == 1 else -1
            for comb in combinations(coins, r):
                subsets.append((math.lcm(*comb), sign))

        low, high = 1, k * min(coins)
        while low < high:
            mid = (low + high) // 2
            count = sum(sign * (mid // lcm) for lcm, sign in subsets)
            
            if count >= k:
                high = mid
            else:
                low = mid + 1
                
        return low