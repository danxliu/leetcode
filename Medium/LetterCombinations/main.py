def appendToListElems(char, lst):
    for i in range(len(lst)):
        lst[i] = str(char) + str(lst[i])
    return lst


def letterCombinations(digits):
    """
    :type digits: str
    :rtype: List[str]
    """
    if (len(digits) == 0):
        return []
    next = letterCombinations(digits[1:])
    if not next:
        next = [""]
    if (digits[0] == "2"):
        return ["a" + str(i) for i in next] + ["b" + str(i) for i in next] + ["c" + str(i) for i in next]
    if (digits[0] == "3"):
        return ["d" + str(i) for i in next] + ["e" + str(i) for i in next] + ["f" + str(i) for i in next]
    if (digits[0] == "4"):
        return ["g" + str(i) for i in next] + ["h" + str(i) for i in next] + ["i" + str(i) for i in next]
    if (digits[0] == "5"):
        return ["j" + str(i) for i in next] + ["k" + str(i) for i in next] + ["l" + str(i) for i in next]
    if (digits[0] == "6"):
        return ["m" + str(i) for i in next] + ["n" + str(i) for i in next] + ["o" + str(i) for i in next]
    if (digits[0] == "7"):
        return ["p" + str(i) for i in next] + ["q" + str(i) for i in next] + ["r" + str(i) for i in next] + ["s" + str(i) for i in next]
    if (digits[0] == "8"):
        return ["t" + str(i) for i in next] + ["u" + str(i) for i in next] + ["v" + str(i) for i in next]
    if (digits[0] == "9"):
        return ["w" + str(i) for i in next] + ["x" + str(i) for i in next] + ["y" + str(i) for i in next] + ["z" + str(i) for i in next]


print(letterCombinations("23"))
