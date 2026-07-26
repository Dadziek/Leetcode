class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647

        if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0):
            con = True
        else:
            con = False

        temp = abs(dividend)
        abs_divisor = abs(divisor)
        counter = 0

        while temp >= abs_divisor:
            current_divisor = abs_divisor
            multiple = 1

            while temp >= current_divisor * 2:
                current_divisor *= 2
                multiple *= 2

            temp -= current_divisor
            counter += multiple

        if con:
            return -counter
        return counter