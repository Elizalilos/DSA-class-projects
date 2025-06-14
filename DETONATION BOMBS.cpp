// DETONATION BOMBS

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int totalBombs = bombs.size();
        

        vector<vector<int>> adjacency(totalBombs);
        
        for (int i = 0; i < totalBombs; i++) {
            long long x_i = bombs[i][0];
            long long y_i = bombs[i][1];
            long long radius = bombs[i][2];
            
            for (int j = 0; j < totalBombs; j++) {
                if (i == j) continue;
                
                long long x_j = bombs[j][0];
                long long y_j = bombs[j][1];
                
                // Compute squared distance between bombs i and j
                long long dx = x_i - x_j;
                long long dy = y_i - y_j;
                long long distanceSquared = dx * dx + dy * dy;
                
               
                if (distanceSquared <= radius * radius) {
                    adjacency[i].push_back(j);
                }
            }
        }
        
        int maxCount = 0;
        

        for (int start = 0; start < totalBombs; start++) {
            vector<bool> visited(totalBombs, false);
            int detonatedCount = countDetonations(start, adjacency, visited);
            if (detonatedCount > maxCount) {
                maxCount = detonatedCount;
            }
        }
        
        return maxCount;
    }

private:
    int countDetonations(int current, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[current] = true;
        int total = 1; // current bomb 
        
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                total += countDetonations(neighbor, graph, visited);
            }
        }
        return total;
    }
};
