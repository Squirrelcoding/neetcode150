from typing import List

class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Loop through diagonal
        for i in range(9):
            # get row and column
            counts = {}
            row = board[i]
            column = [board[j][i] for j in range(9) if j != i]
            for c in row:
                if c not in counts:
                    counts[c] = 1
                else:
                    counts[c] += 1

            for c in column:
                if c not in counts:
                    counts[c] = 1
                else:
                    counts[c] += 1
            print(counts)
            # verify that it's all 1 or 0
            for key in counts:
                if key == ".":
                    continue
                if counts[key] != 1:
                    return False


        # Loop through 3x3 grids
        for i in range(3):
            for j in range(3):
                digits = []
                for k in range(3):
                    for l in range(3):
                        digits.append([board[3 * i + k][3 * j + l]])
                counts = {}
                for d in digits:
                    if d not in counts:
                        counts[d] = 1
                    else:
                        counts[d] += 1
                for key in counts:
                    if key == ".":
                        continue
                    if counts[key] != 1:
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
