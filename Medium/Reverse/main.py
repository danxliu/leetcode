def reverse(x):
    """
    :type x: int
    :rtype: int
    """
    neg = True if (x < 0) else False
    x = abs(x)
    ans = str(x)
    rev = 0
    for i in ans[::-1]:
        rev = rev*10 + int(i)
    if (rev > 2147483647):
        return 0
    return -1 * rev if neg else rev


print(reverse(123))
