// SNAKE AND LADDER.
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<vector<int>> PossiblePaths;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        PossiblePaths.push({1, 0}); // {cell number, steps}

        while (!PossiblePaths.empty()) {
            vector<int> current = PossiblePaths.front();
            int cell = current[0];
            int steps = current[1];
            PossiblePaths.pop();

            for (int move = 1; move <= 6; ++move) {
                int nextCell = cell + move;
                if (nextCell > n * n) continue;

                pair<int, int> coords = getCoordinates(nextCell, n);
                int row = coords.first;
                int col = coords.second;

                if (visited[row][col]) continue;
                visited[row][col] = true;

              
                if (board[row][col] != -1) {
                    nextCell = board[row][col];
                }

                // reached the final cell
                if (nextCell == n * n) {
                    return steps + 1;
                }

                PossiblePaths.push({nextCell, steps + 1});
            }
        }

        return -1; 
    }

    pair<int, int> getCoordinates(int cell, int n) {
        int quot = (cell - 1) / n;
        int rem = (cell - 1) % n;

        int row = n - 1 - quot;
        int col = (quot % 2 == 0) ? rem : n - 1 - rem;

        return {row, col};
    }
};
