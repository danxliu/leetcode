class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        sign = 1
        if numerator < 0:
            numerator *= -1
            sign *= -1
        if denominator < 0:
            denominator *= -1
            sign *= -1
        ans = ""
        if sign == -1:
            ans += '-'
        ans += str(numerator // denominator)
        numerator = numerator % denominator
        if numerator == 0:
            return ans
        ans += '.'

        mp = {}
        mp[numerator] = len(ans)
        while (numerator != 0):
            numerator *= 10
            ans += str(numerator // denominator)
            numerator = numerator % denominator
            if numerator in mp:
                ans = ans[:mp[numerator]] + '(' + ans[mp[numerator]:] + ')'
                break
            mp[numerator] = len(ans)
        return ans
