class Solution(object):
    def isIsomorphic(self, s, t):
        map_s = {i: '' for i in list(set([j for j in s]))}
        map_t = {i: '' for i in list(set([j for j in t]))}

        for i, j in zip(s, t):
            if map_s[i] == '':
                map_s[i] = j
            elif map_s[i] != j:
                return False

            if map_t[j] == '':
                map_t[j] = i
            elif map_t[j] != i:
                return False

        return True