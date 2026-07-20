class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid[0])
        flat = [val for row in grid for val in row]
        k %= len(flat)
        shifted = flat[-k:] + flat[:-k] if k else flat
        return [shifted[i : i + n] for i in range(0, len(shifted), n)]   