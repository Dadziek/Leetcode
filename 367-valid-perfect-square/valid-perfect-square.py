class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        pre = 1e-15
        side = num

        while True:
            next_side = (side + num / side) / 2
            if abs(side - next_side) < pre:
                break
            side = next_side

        if int(next_side) * int(next_side) == num:
            return True
        return False