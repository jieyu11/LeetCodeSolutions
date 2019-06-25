class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if " " not in s:
            return s
        ls = s.split()
        ls.reverse()
        return " ".join( ls )
