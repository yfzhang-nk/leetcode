class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == '':
            return []
        keyboard9 = {
            '2' : 'abc',
            '3' : 'def',
            '4' : 'ghi',
            '5' : 'jkl',
            '6' : 'mno',
            '7' : 'pqrs',
            '8' : 'tuv',
            '9' : 'wxyz'
        }
        result = ['']
        for ch in digits:
            tmp = result
            result = []
            for last_str in tmp:
                for append_char in keyboard9[ch]:
                    result.append(last_str + append_char)
        return result
