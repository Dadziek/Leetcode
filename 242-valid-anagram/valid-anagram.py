class Solution(object):
    def isAnagram(self, s, t):
        s, t = [i for i in s], [i for i in t]
        return sorted(s) == sorted(t)
        