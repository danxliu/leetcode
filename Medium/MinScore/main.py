def minScore(n, roads):
    """
    :type n: int
    :type roads: List[List[int]]
    :rtype: int
    """
    visited = [False for i in range(100000)]
    betterroads = {}
    for i in roads:
        if (not i[0] in betterroads):
            betterroads[i[0]] = [[i[1], i[2]]]
        else:
            betterroads[i[0]].append([i[1], i[2]])
        if (not i[1] in betterroads):
            betterroads[i[1]] = [[i[0], i[2]]]
        else:
            betterroads[i[1]].append([i[0], i[2]])
    ans = 10000
    q = [1]
    while q:
        cur = q.pop()
        visited[i[0]] = True
        for i in betterroads[cur]:
            if not visited[i[0]]:
                ans = min(ans, i[1])
                q.append(i[0])
    return ans
