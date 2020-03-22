class SodukuSolver:
    def __init__(self, bo):
        self.bo = bo
        self.solve()

    def vacant(self):
        for i in range(len(self.bo)):
            for j in range(len(self.bo[0])):
                if self.bo[i][j] == 0:
                    return (i, j)
        return None

    def valid(self, num, pos):
        for i in range(len(self.bo[0])):
            if self.bo[pos[0]][i] == num:
                return False
        for i in range(len(self.bo[0])):
            if self.bo[i][pos[1]] == num:
                return False
        for i in range(3):
            for j in range(3):
                if self.bo[pos[0] - (pos[0]%3) + j][pos[1] - (pos[1]%3) + j] == num:
                    return False
        return True

    def solve(self):
        if not self.vacant():
            return True
        else:
            row, col = self.vacant()
            for i in range(1,10):
                if self.valid(i , (row,col)):
                    self.bo[row][col] = i
                    if self.solve():
                        return True
                self.bo[row][col] = 0
            return False


    def print_board(self):
        for i in range(len(self.bo)):
            if i%3 == 0 and i != 0:
                print('-----------------------')
            for j in range(len(self.bo[0])):
                if j%3 == 0 and j != 0:
                    print(" | ", end = "")
                
                if j == 8:
                    print(self.bo[i][j])
                else:
                    print(str(self.bo[i][j]) + " ", end = "")
    def solution(self):
        return self.bo


board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]]
s = SodukuSolver(board)
sol = s.solution()
s.print_board()
#print_board(board)
#solve(board)
#print("\n")
#print_board(board)
