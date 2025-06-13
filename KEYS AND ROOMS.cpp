// KEYS AND ROOMS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visitedRooms;
        vector<int> toVisit = {0};
        visitedRooms.insert(0);

        for (int i = 0; i < toVisit.size(); ++i) {
            for (int key : rooms[toVisit[i]]) {
                if (visitedRooms.insert(key).second) {
                    toVisit.push_back(key);
                }
            }
        }

        return visitedRooms.size() == rooms.size();
    }
};
