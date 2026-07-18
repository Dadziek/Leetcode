class Solution:
    def reverseBits(self, n: int) -> int:
        if n == 0:
            return 0

        bin_n = ""
        while n > 0:
            bin_n = str(n % 2) + bin_n
            n //= 2

        bin_n = "0" * (32 - len(bin_n)) + bin_n

        new_n, power = 0, 0
        for i in range(0, len(bin_n)):
            new_n += int(bin_n[i]) * (2**power)
            power += 1
            
        return new_n