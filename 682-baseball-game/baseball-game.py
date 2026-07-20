class Solution:
    def calPoints(self, operations: List[str]) -> int:
        points = []

        for operation in operations:
            if operation == "+":
                points.append(points[-1] + points[-2])
            elif operation == "D":
                points.append(points[-1] * 2)
            elif operation == "C":
                points.pop()
            else:
                points.append(int(operation))
        
        return sum(points)
