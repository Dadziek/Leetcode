class Solution(object):
    def generate(self, numRows):
        tab = [[1]]
        last = tab[0]

        for i in range(1, numRows):
            new_tab = [0 for _ in range(len(last)+1)]
            new_tab[0] = new_tab[-1] = 1

            if len(new_tab) > 2:
                for j in range(1, len(new_tab)-1):
                    new_tab[j] = last[j-1] + last[j]
            tab.append(new_tab)
            last = new_tab

        return tab