class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root

        for letter in word:
            ind = ord(letter) - ord('a')
            if not cur.children[ind]:
                cur.children[ind] = TrieNode()
            cur = cur.children[ind]
        cur.end = True

    def search(self, word: str) -> bool:

        def recurse(cur, i):
            if not cur:
                return False

            if i >= len(word):
                return cur.end


            if word[i] == '.':
                return any([recurse(child, i+1) for child in cur.children])
            ind = ord(word[i]) - ord('a')
            return recurse(cur.children[ind], i+1)
        return recurse(self.root, 0)

w = WordDictionary()

w.addWord("day")
w.addWord("bay")
w.addWord("may")
print(w.search("b.."))
