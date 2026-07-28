class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        valid_times = []

        for hour in range(12):
            for minute in range(60):
                if (bin(hour).count('1') + bin(minute).count('1')) == turnedOn:
                    valid_times.append(f"{hour}:{minute:02d}")
                
        return valid_times