class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 0:
            return 0
        side = x
        pre = 1e-5
        while abs(side - x/side) / 2 > pre:
            side = (side + x/side)/2
        return int(side)