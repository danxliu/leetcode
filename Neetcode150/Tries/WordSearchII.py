from typing import List

class TrieNode():
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        ans = set()

        n = len(board)
        m = len(board[0])

        trieRoot = TrieNode()

        # Add words to trie
        for word in words:
            cur = trieRoot
            for letter in word:
                ind = ord(letter) - ord('a')
                if not cur.children[ind]:
                    cur.children[ind] = TrieNode()
                cur = cur.children[ind]
            cur.end = True
        

        vis = set()
        def dfs(node, r, c, word):
            if not node:
                return

            if node.end:
                ans.add(word)

            if r < 0 or c < 0 or r >= n or c >= m:
                return
            ind = ord(board[r][c]) - ord('a')
            if not node.children[ind]:
                return
            if (r, c) in vis:
                return
            word += board[r][c]
            vis.add((r, c))
            dfs(node.children[ind], r-1, c, word)
            dfs(node.children[ind], r+1, c, word)
            dfs(node.children[ind], r, c-1, word)
            dfs(node.children[ind], r, c+1, word)
            vis.remove((r, c))

        
        for r in range(n):
            for c in range(m):
                dfs(trieRoot, r, c, "")
        return list(ans)