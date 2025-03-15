def lengthOfLongestSubstring(s):
    i = 0
    j = 0
    mx = 0
    while (j <= len(s)):
        if j == len(s) or s[j] in s[i:j]:
            mx = max(mx, j-i)
            while (j < len(s) and i < j and s[j] in s[i:j]):
                i += 1
        j += 1
    return mx


print(lengthOfLongestSubstring("pwwkew"))
