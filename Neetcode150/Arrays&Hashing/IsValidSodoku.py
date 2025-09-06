from typing import *

class Solution:
    def isUnique(self, arr: List[str]) -> bool:
        vis = set()
        for i in arr:
            if i == '.':
                continue
            if i in vis:
                return False
            vis.add(i)
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # Check rows
        for i in range(9):
            row = board[i]
            if not self.isUnique(row):
                return False
        
        # Check cols
        for i in range(9):
            col = []
            for j in range(9):
                col.append(board[j][i])
            if not self.isUnique(col):
                return False
        
        # Check squares
        for i in range(3):
            for j in range(3):
                # Get top left square
                tr = i * 3
                tc = j * 3
                sq = []
                for k in range(tr, tr+3):
                    for l in range(tc, tc+3):
                        sq.append(board[k][l])
                if not self.isUnique(sq):
                    return False
        return True

s = Solution()
board = [["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

print(s.isValidSudoku(board))