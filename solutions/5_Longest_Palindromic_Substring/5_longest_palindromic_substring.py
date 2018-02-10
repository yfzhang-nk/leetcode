class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = '#' + '#'.join(s) + '#'
        pos, mx, length = 0, 0, len(s)
        pal = [0] * length
        maxlen, maxidx = 0, 0
        for idx in range(length):
            if idx < mx:
                pal[idx] = min(pal[2*pos - idx], mx - idx)
            else:
                pal[idx] = 1
            while idx - pal[idx] >= 0 and idx + pal[idx] < length and s[idx-pal[idx]] == s[idx+pal[idx]]:
                pal[idx] += 1
            if mx < pal[idx] + idx - 1:
                mx = pal[idx] + idx - 1
                pos = idx
            if maxlen < pal[idx]:
                maxlen = pal[idx]
                maxidx = idx
        return s[maxidx-maxlen+2:maxidx+maxlen-1:2]

if __name__ == '__main__':
    solution = Solution()
    solution.longestPalindrome('a')
