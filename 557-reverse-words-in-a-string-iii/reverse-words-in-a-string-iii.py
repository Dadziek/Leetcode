class Solution(object):
    def reverseWords(self, s):
        s = s.split(" ")
        return " ".join([i[::-1] for i in s])
        