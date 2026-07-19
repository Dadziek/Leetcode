class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        tab = []
        for i in range(left, right + 1):
            if self.dividingDigits(i):
                tab.append(i)
        return tab

    def dividingDigits(self, num: int) -> bool:
        temp = num
        while temp > 0:
            if temp % 10 == 0:
                return False
            elif num % (temp % 10) != 0:
                return False
            temp //= 10
        return True
 