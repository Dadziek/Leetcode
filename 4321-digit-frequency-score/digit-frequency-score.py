class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        my_dict = {}

        while n > 0:
            try:
                my_dict[n % 10] += 1
            except KeyError:
                my_dict[n % 10] = 1
            n //= 10
        
        return sum([key * amount for key, amount in my_dict.items()])

        