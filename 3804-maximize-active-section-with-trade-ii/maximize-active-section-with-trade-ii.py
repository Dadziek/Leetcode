class SparseTable:
    def __init__(self, nums: list[int]):
        n = len(nums)
        self.st = [nums]
        while (1 << len(self.st)) <= n:
            k = 1 << (len(self.st) - 1)
            prev = self.st[-1]
            self.st.append([max(prev[j], prev[j + k]) for j in range(n - (k * 2) + 1)])

    def query(self, l: int, r: int) -> int:
        if l > r: return 0
        i = (r - l + 1).bit_length() - 1
        return max(self.st[i][l], self.st[i][r - (1 << i) + 1])
        

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: list[list[int]]) -> list[int]:
        ones = s.count('1')
        
        zero_groups = []
        zero_group_index = []
        for i, char in enumerate(s):
            if char == '0':
                if i > 0 and s[i - 1] == '0':
                    zero_groups[-1][1] += 1
                else:
                    zero_groups.append([i, 1])
            zero_group_index.append(len(zero_groups) - 1)

        if not zero_groups:
            return [ones] * len(queries)

        merge_lengths = [a[1] + b[1] for a, b in zip(zero_groups, zero_groups[1:])]
        st = SparseTable(merge_lengths)

        ans = []
        for l, r in queries:
            g_l, g_r = zero_group_index[l], zero_group_index[r]
            
            left = -1 if g_l == -1 else (zero_groups[g_l][1] - (l - zero_groups[g_l][0]))
            right = -1 if g_r == -1 else (r - zero_groups[g_r][0] + 1)
            
            start_adj = g_l + 1
            end_adj = (g_r if s[r] == '1' else g_r - 1) - 1
            
            res = ones
            if s[l] == '0' and s[r] == '0' and g_l + 1 == g_r:
                res = max(res, ones + left + right)
            elif start_adj <= end_adj:
                res = max(res, ones + st.query(start_adj, end_adj))
                
            if s[l] == '0' and g_l + 1 <= (g_r if s[r] == '1' else g_r - 1):
                res = max(res, ones + left + zero_groups[g_l + 1][1])
            if s[r] == '0' and g_l < g_r - 1:
                res = max(res, ones + right + zero_groups[g_r - 1][1])
                
            ans.append(res)
            
        return ans
