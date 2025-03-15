def allPathsSourceTarget(graph):
    """
    :type graph: List[List[int]]
    :rtype: List[List[int]]
    """
    ans = []

    def dfs(path):
        cur = path[-1]
        if cur == len(graph)-1:
            ans.append(path)
            return
        for n in graph[cur]:
            dfs(path + [n])
    dfs([0])
    return ans
