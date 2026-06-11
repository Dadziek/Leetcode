class Solution(object):
    def reverse(self, x): 
        minus = False
        if x < 0:
            x *= (-1)
            minus = True
        temp = x
        length = -1

        while temp > 0:
            temp //= 10
            length += 1

        new_x = 0

        while x > 0:
            new_x += (x % 10) * 10 ** length
            length -= 1
            x //= 10

        if minus:
            new_x *= -1

        if new_x < -2**31 or new_x > 2**31 - 1:
            return 0
            
        return new_x
            