// NUMBER OF PROVINCES

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Create adjacency list from the matrix
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjacencyList[i].push_back(j);
                    // adjacencyList[j].push_back(i); // optional because matrix is symmetric
                }
            }
        }

        // Visited array to keep track of visited nodes
        vector<int> visited(n, 0);

        int provinceCount = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                provinceCount++;
                dfs(i, adjacencyList, visited);
            }
        }

        return provinceCount;
    }

private:
    void dfs(int node, vector<vector<int>>& adjacencyList, vector<int>& visited) {
        visited[node] = 1;

        for (int neighbor : adjacencyList[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adjacencyList, visited);
            }
        }
    }
};
