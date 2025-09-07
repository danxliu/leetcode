class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class PrefixTree:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for letter in word:
            ind = ord(letter) - ord('a')
            if not cur.children[ind]:
                cur.children[ind] = TrieNode()
            cur = cur.children[ind]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for letter in word:
            ind = ord(letter) - ord('a')
            if not cur.children[ind]:
                return False
            cur = cur.children[ind]
        return cur.end

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for letter in prefix:
            ind = ord(letter) - ord('a')
            if not cur.children[ind]:
                return False
            cur = cur.children[ind]
        return True

prefixTree = PrefixTree()

prefixTree.insert("dog")
print(prefixTree.search("dog"))
print(prefixTree.search("do"))
print(prefixTree.startsWith("do"))
prefixTree.insert("do")
print(prefixTree.search("do"))