// MAX AREA ISLAND

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Visited matrix to mark cells we've already counted
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Check every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If cell is land and not visited yet, start DFS
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int area = dfs(grid, visited, i, j, rows, cols);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int rows, int cols) {
        // Check if out of bounds or water or already visited
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return 0;
        }
        if (grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        current cell as visited
        visited[row][col] = true;

        int area = 1;

        // Explore neighbors 
        area += dfs(grid, visited, row - 1, col, rows, cols);
        area += dfs(grid, visited, row + 1, col, rows, cols);
        area += dfs(grid, visited, row, col - 1, rows, cols);
        area += dfs(grid, visited, row, col + 1, rows, cols);

        return area;
    }
};
