class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 0
        start = 1
        str_idx = dict(zip([chr(ch) for ch in range(256)], [0]*256))
        for idx in range(1, len(s)+1):
            ch = s[idx-1]
            if str_idx[ch] >= start:
                start = str_idx[ch] + 1
            else:
                ret = max(ret, idx-start+1)
            str_idx[ch] = idx
        return ret

if __name__ == '__main__':
    solution = Solution()
    print(solution.lengthOfLongestSubstring('abba'))
    print(solution.lengthOfLongestSubstring('c'))
