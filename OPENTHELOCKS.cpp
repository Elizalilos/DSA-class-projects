// SOLUTION TO OPEN THE LOCKS PROBLEM
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> Steps;
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000")) return -1;

        Steps.push({"0000", 0});
        visited.insert("0000");

        while (!Steps.empty()) {
            string val = Steps.front().first;
            int step = Steps.front().second;
            Steps.pop();

            if (val == target) return step;

            for (int i = 0; i < 4; i++) {
                for (int d = -1; d <= 1; d += 2) {  // only -1 and +1
                    string next = val;
                    next[i] = (next[i] - '0' + d + 10) % 10 + '0';

                    if (!visited.count(next)) {
                        visited.insert(next);
                        Steps.push({next, step + 1});
                    }
                }
            }
        }

        return -1; // unreachable
    }
};
