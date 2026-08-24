class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        result, temp = [], 0

        while i >= 0 or j >= 0 or temp > 0:
            if i >= 0:
                a = ord(num1[i]) - ord("0")
            else:
                a = 0
            
            if j >= 0:
                b = ord(num2[j]) - ord("0") if j >= 0 else 0
            else:
                b = 0
        
            s = a + b + temp

            result.append(str(s % 10))
            temp = s // 10

            i -= 1
            j -= 1
        
        return "".join(reversed(result))
