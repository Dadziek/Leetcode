class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd = sum([i for i in range(1, n*2+1) if i % 2 != 0])
        sumEven = sum([i for i in range(1, n*2+1) if i % 2 == 0])

        print(sumOdd)
        print(sumEven)

        while sumOdd != sumEven:
            if sumOdd > sumEven:
                sumOdd -= sumEven
            else:
                sumEven -= sumOdd

        return sumOdd