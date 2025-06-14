// BUS ROUTE
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;

        // Map stop to  bus route
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

      
        queue<pair<int, int>> q;
        q.push({S, 0});

        
        unordered_set<int> visitedStops;
        visitedStops.insert(S);

        
        vector<bool> visitedRoutes(routes.size(), false);

        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();

            int currentStop = front.first;
            int busesTaken = front.second;

            if (currentStop == T) {
                return busesTaken;
            }

          
            vector<int> routesThroughStop = stopToRoutes[currentStop];

            for (int routeIndex : routesThroughStop) {
                if (visitedRoutes[routeIndex]) continue;

                visitedRoutes[routeIndex] = true;

                // Visit all stops in this route
                for (int stop : routes[routeIndex]) {
                    if (visitedStops.find(stop) == visitedStops.end()) {
                        visitedStops.insert(stop);
                        q.push({stop, busesTaken + 1});
                    }
                }
            }
        }

        return -1;
    }
};
