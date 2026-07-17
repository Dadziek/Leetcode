class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        max_val = max(nums)

        freq = [0] * (max_val + 1)
        for num in nums:
            freq[num] += 1
            
        cnt = [0] * (max_val + 1)
        for g in range(1, max_val + 1):
            for multiple in range(g, max_val + 1, g):
                cnt[g] += freq[multiple]
                
        exact_gcd = [0] * (max_val + 1)
        for g in range(max_val, 0, -1):
            total_pairs = (cnt[g] * (cnt[g] - 1)) // 2
            minus = 0
            for multiple in range(2 * g, max_val + 1, g):
                minus += exact_gcd[multiple]
            exact_gcd[g] = total_pairs - minus
  
        prefix_sums = [0] * (max_val + 1)
        for g in range(1, max_val + 1):
            prefix_sums[g] = prefix_sums[g - 1] + exact_gcd[g]
            
        ans = []
        for q in queries:
            low = 1
            high = max_val
            target_g = max_val
            
            while low <= high:
                mid = (low + high) // 2
                if prefix_sums[mid] > q:
                    target_g = mid 
                    high = mid - 1
                else:
                    low = mid + 1
                    
            ans.append(target_g)
            
        return ans