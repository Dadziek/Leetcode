class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        occupied = defaultdict(int)
        for row, seat in reservedSeats:
            if 2 <= seat <= 9:
                occupied[row] |= (1 << (seat - 2))
        
        left_mask = 0b00001111
        middle_mask = 0b00111100
        right_mask = 0b11110000
        
        max_groups = 0

        for row, mask in occupied.items():
            if (mask & left_mask) == 0 and (mask & right_mask) == 0:
                max_groups += 2
            elif (mask & left_mask) == 0 or (mask & middle_mask) == 0 or (mask & right_mask) == 0:
                max_groups += 1
                
        empty_rows = n - len(occupied)
        max_groups += empty_rows * 2
    
        return max_groups