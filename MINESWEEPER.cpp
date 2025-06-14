// MINESWEEPER

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];

        // mine already checked
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }

        // near cells
        reveal(board, row, col);

        return board;
    }

    void reveal(vector<vector<char>>& board, int r, int c) {

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;

        
        if (board[r][c] != 'E') return;

        
        int mines = countMines(board, r, c);

        if (mines > 0) {
            board[r][c] = mines + '0';
        } else {
            // no mines - check neighbors
            board[r][c] = 'B';

            // check all 8 directions
            reveal(board, r + 1, c);
            reveal(board, r - 1, c);
            reveal(board, r, c + 1);
            reveal(board, r, c - 1);
            reveal(board, r + 1, c + 1);
            reveal(board, r + 1, c - 1);
            reveal(board, r - 1, c + 1);
            reveal(board, r - 1, c - 1);
        }
    }

    int countMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        for (auto d : directions) {
            int newR = r + d.first;
            int newC = c + d.second;

            if (newR >= 0 && newC >= 0 && newR < board.size() && newC < board[0].size()) {
                if (board[newR][newC] == 'M') {
                    count++;
                }
            }
        }

        return count;
    }
};
