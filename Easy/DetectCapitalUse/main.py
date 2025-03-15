def detectCapitalUse(word):
    """
    :type word: str
    :rtype: bool
    """
    if word[0].islower():
        return not any([i.isupper() for i in word])
    else:
        return all([i.isupper() for i in word]) or all([word[i].islower() for i in range(1, len(word))])


print(detectCapitalUse("Google"))
