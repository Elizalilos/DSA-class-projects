// WORD LADDER
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Put all words into a set for fast lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; // endWord not reachable
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // we start at beginWord with step count = 1

        // To keep track of visited words
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            pair<string, int> current = q.front();
            q.pop();

            string word = current.first;
            int steps = current.second;

        
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                   
                    if (temp == endWord) {
                        return steps + 1;
                    }

                   
                    if (wordSet.find(temp) != wordSet.end() && visited.find(temp) == visited.end()) {
                        visited.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        return 0; 
    }
};
