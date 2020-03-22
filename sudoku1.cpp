#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int pos) {
        // goal is: when I reach the end, stop
        if(pos == 81) {
            return true;
        }
        int row = pos/9, col = pos%9;
        // choice 1: for 1~9, do nothing, check the next one
        if(board[row][col] != '.') {
            return solveSudoku(board, pos+1);
        }
        // choice 2: for '.', try all possible candidates
        else {
            for(int i = 0; i < 9; ++i) {
                char candidate = '1' + i;
                // constrain: same row/col/block can't have duplicate elements
                // before put any candidate, check whether it is a valid solution
                if(valid(board, pos, candidate)) {
                    board[row][col] = candidate;
                    if(solveSudoku(board, pos+1)) {
                        return true;
                    }
                }
            }
        }
        board[row][col] = '.';
        return false;
    }
    bool valid(vector<vector<char>>& board, int pos, char candidate) {
        int row = pos/9, col = pos%9;
        for(int col = 0; col < 9; ++col) {
            if(board[row][col] == candidate) {
                return false;
            }
        }
        for(int row = 0; row < 9; ++row) {
            if(board[row][col] == candidate) {
                return false;
            }
        }
        int upper_row = 3*(row/3), upper_col = 3*(col/3);
        for(int i = 0; i < 9; ++i) {
            if(board[upper_row + i/3][upper_col + i%3] == candidate) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    
}