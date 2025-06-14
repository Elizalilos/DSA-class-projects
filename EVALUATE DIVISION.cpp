//EVALUATE DIVISION


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //adjacency list: map from variable to vector of (neighbor, weight)
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            double val = values[i];
            
            graph[from].push_back({to, val});
            graph[to].push_back({from, 1.0 / val});
        }

        vector<double> answers;

        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            // variable not in graph
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                answers.push_back(-1.0);
                continue;
            }


            if (start == end) {
                answers.push_back(1.0);
                continue;
            }

            
            queue<pair<string, double>> q;
            q.push({start, 1.0});

            // Visited map to keep track of visited nodes, reset for every query
            unordered_map<string, bool> visited;
            visited[start] = true;

            bool found = false;
            double result = -1.0;

            
            while (!q.empty()) {
                pair<string, double> current = q.front();
                q.pop();

                string currentNode = current.first;
                double currentVal = current.second;

                // look at all neighbors
                for (int j = 0; j < graph[currentNode].size(); j++) {
                    string neighbor = graph[currentNode][j].first;
                    double weight = graph[currentNode][j].second;

                    
                    if (neighbor == end) {
                        result = currentVal * weight;
                        found = true;
                        break;
                    }

                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, currentVal * weight});
                    }
                }

                if (found) {
                    break;
                }
            }

            answers.push_back(result);
        }

        return answers;
    }
};
