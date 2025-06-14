// RACE CAR
class Solution {
public:
    int racecar(int target) {
        // Queue will store: position, speed, number of moves
        queue<vector<int>> q;
        q.push({0, 1, 0}); // starting at 0 with speed +1, 0 moves

        // Visited set to avoid revisiting the same (position, speed)
        set<pair<int, int>> visited;

        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();

            int pos = current[0];
            int speed = current[1];
            int moves = current[2];

            // If target is reached
            if (pos == target) {
                return moves;
            }

            // Skip if already visited
            if (visited.count({pos, speed}) > 0) {
                continue;
            }

            visited.insert({pos, speed});

            // Option 1: Accelerate
            int newPos = pos + speed;
            int newSpeed = speed * 2;

            // Only consider states within a reasonable range
            if (abs(newPos) <= 2 * target) {
                q.push({newPos, newSpeed, moves + 1});
            }

            // Option 2: Reverse direction
            int reverseSpeed = speed > 0 ? -1 : 1;
            q.push({pos, reverseSpeed, moves + 1});
        }

        return -1;
    }
};
