// SURROUNDED REGIONS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // loop over borders
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][col - 1] == 'O') {
                dfs(i, col - 1, board);
            }
        }

        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[row - 1][j] == 'O') {
                dfs(row - 1, j, board);
            }
        }

        // flip things
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // surrounded
                }
                if (board[i][j] == '*') {
                    board[i][j] = 'O'; // safe
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (board[r][c] != 'O') {
            return;
        }

        board[r][c] = '*'; // mark visited and safe

        dfs(r + 1, c, board); 
        dfs(r - 1, c, board); 
        dfs(r, c + 1, board); 
        dfs(r, c - 1, board); 
    }
};
