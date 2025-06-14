//ROTTING ORANGES

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int time = 0;
        int fresh = 0;

        // find initial rotten oranges and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0}); // rotten orange
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // do BFS manually (not using direction array)
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            int i = cur[0];
            int j = cur[1];
            int t = cur[2];

            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j, t + 1});
                fresh--;
            }
            if (i + 1 < rows && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j, t + 1});
                fresh--;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1, t + 1});
                fresh--;
            }
            if (j + 1 < cols && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1, t + 1});
                fresh--;
            }

            time = t; // this will always store last time
        }

        if (fresh > 0) {
            return -1;
        }

        return time;
    }
};
