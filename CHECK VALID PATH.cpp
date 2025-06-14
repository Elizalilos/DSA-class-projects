// CHECK VALID PATH
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Movement directions: up, down, left, right
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        // Map from tile type to allowed directions (0=up, 1=down, 2=left, 3=right)
        unordered_map<int, vector<int>> typeToDir = {
            {1, {2, 3}}, // left, right
            {2, {0, 1}}, // up, down
            {3, {1, 2}}, // down, left
            {4, {1, 3}}, // down, right
            {5, {0, 2}}, // up, left
            {6, {0, 3}}  // up, right
        };

        // What direction is the opposite of another (needed for two-way connection)
        unordered_map<int, int> opposite = {
            {0, 1}, {1, 0}, {2, 3}, {3, 2}
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // If we reached bottom-right
            if (row == m - 1 && col == n - 1) {
                return true;
            }

            int tileType = grid[row][col];

            // Check all directions from this tile
            for (int dir : typeToDir[tileType]) {
                int newRow = row + dRow[dir];
                int newCol = col + dCol[dir];

                // Check boundaries
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    int nextType = grid[newRow][newCol];
                    // Check if the next tile connects back using opposite direction
                    vector<int> nextDirs = typeToDir[nextType];
                    for (int nextDir : nextDirs) {
                        if (nextDir == opposite[dir]) {
                            visited[newRow][newCol] = true;
                            q.push({newRow, newCol});
                            break;
                        }
                    }
                }
            }
        }

        return false; // Could not reach bottom-right
    }
};
