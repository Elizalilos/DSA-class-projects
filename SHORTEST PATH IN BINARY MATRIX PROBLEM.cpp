// SOLUTION FOR THE SHORTEST PATH IN BINARY MATRIX PROBLEM

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> BFs;

        int size = grid.size();
        int step = 0;

        if (grid[0][0] != 0 || grid[size - 1][size - 1] != 0) {
            return -1; // we can't visit start or end
        }

        BFs.push({0, 0, step});

        while (!BFs.empty()) {
            vector<int> ELTs = BFs.front();
            BFs.pop();

            int i = ELTs[0];
            int j = ELTs[1];
            int step = ELTs[2];

            if (i == size - 1 && j == size - 1) {
                return step + 1;
            }

            grid[i][j] = -3; // mark visited

            // check 8 directions
            if (j + 1 < size && grid[i][j + 1] == 0){
                BFs.push({i, j + 1, step + 1});
                grid[i][j + 1] = -3;
            }
               
            if (i + 1 < size && grid[i + 1][j] == 0){
                BFs.push({i + 1, j, step + 1});
                grid[i + 1][j ] = -3; 
            }
                

            if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 0){
                BFs.push({i - 1, j - 1, step + 1});
                grid[i - 1][j - 1] = -3;
            }
                
            if (i - 1 >= 0 && grid[i - 1][j] == 0){
                BFs.push({i - 1, j, step + 1});
                grid[i - 1][j] = -3;
            }
                
            if (j - 1 >= 0 && grid[i][j - 1] == 0){
                BFs.push({i, j - 1, step + 1});
                grid[i][j - 1] = -3;
            }
                
            if (j - 1 >= 0 && i + 1 < size && grid[i + 1][j - 1] == 0){
                BFs.push({i + 1, j - 1, step + 1});
                grid[i + 1][j - 1] = -3;
            }

            if (i - 1 >= 0 && j + 1 < size && grid[i - 1][j + 1] == 0){
                BFs.push({i - 1, j + 1, step + 1});
                grid[i - 1][j + 1] = -3;
            }
                
            if (j + 1 < size && i + 1 < size && grid[i + 1][j + 1] == 0){
                BFs.push({i + 1, j + 1, step + 1});
                grid[i + 1][j + 1] = -3;
            }
        }

        return -1; // no path found
    }
};
