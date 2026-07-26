class Solution:
    def calculate(self, s: str) -> int:
        
        index = 0

        def solve() -> int:
            nonlocal index
            result = 0
            sign = 1 
            
            while index < len(s):
                char = s[index]  
                if char == ' ':
                    index += 1
                elif char.isdigit():
                    num = 0
                    while index < len(s) and s[index].isdigit():
                        num = num * 10 + int(s[index])
                        index += 1
                    result += sign * num
                elif char == '+':
                    sign = 1
                    index += 1
                elif char == '-':
                    sign = -1
                    index += 1
                elif char == '(':
                    index += 1
                    inner_result = solve()
                    result += sign * inner_result
                elif char == ')':
                    index += 1
                    return result       
            return result
        
        return solve()