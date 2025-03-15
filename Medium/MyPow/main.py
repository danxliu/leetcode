def myPow(x, n):
    """
    :type x: float
    :type n: int
    :rtype: float
    """
    if (n == 0 or x == 1):
        return 1
    if (n % 2 == 0):
        m = myPow(x, n//2)
        return m * m
    else:
        return x * myPow(x, n-1)
