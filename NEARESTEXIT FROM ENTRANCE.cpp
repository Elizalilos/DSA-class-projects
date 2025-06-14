// NEAREST EXIT FROM ENTRANCE

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int numOfSteps = -1;

        queue<vector<int>> PossiblePaths;
        int steps = 0;

        entrance.push_back(steps); // the first step = 0;
        PossiblePaths.push(entrance);
        maze[entrance[0]][entrance[1]] = '+'; // mark entrance as visited

        while (!PossiblePaths.empty()) {
            vector<int> Element = PossiblePaths.front();
            int row = Element[0];
            int col = Element[1];
            steps = Element[2];

            // check all 4 directions
            vector<vector<int>> directions = {
                { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
            };

            for (auto dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                // inside the grid and is empty
                if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() && maze[newRow][newCol] == '.') {
                    // check if it's an exit (on the border but not entrance)
                    if (newRow == 0 || newRow == maze.size() - 1 || newCol == 0 || newCol == maze[0].size() - 1) {
                        return steps + 1;
                    }

                    maze[newRow][newCol] = '+'; // mark visited
                    vector<int> newElement = { newRow, newCol, steps + 1 };
                    PossiblePaths.push(newElement);
                }
            }

            PossiblePaths.pop();
        }

        return numOfSteps; // -1 if no exit is found
    }
};
