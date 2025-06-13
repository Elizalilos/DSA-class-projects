//AS FAR FROM THE LAND

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> landQueue;

        // Step 1: Enqueue all land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    landQueue.push({i, j});
                }
            }
        }

        // Edge case: all land or all water
        if (landQueue.empty() || landQueue.size() == n * n) return -1;

        int maxDist = -1;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: Multi-source BFS from land cells
        while (!landQueue.empty()) {
            int sz = landQueue.size();
            maxDist++; // distance increases by 1 at each BFS level

            for (int i = 0; i < sz; i++) {
                auto [row, col] = landQueue.front();
                landQueue.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0) {
                        // Mark visited water with 1 (turn to land to prevent revisiting)
                        grid[newRow][newCol] = 1;
                        landQueue.push({newRow, newCol});
                    }
                }
            }
        }

        return maxDist;
    }
};
