class Solution {
public:
    unordered_set<string> words;
    string abc = "abcdefghijklmnopqrstuvwxyz";

    vector<string> getNeighbors(string word) {
        vector<string> res;
        int size = word.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 26; j++) {
                string temp = word;
                temp[i] = abc[j];
                auto it = words.find(temp);
                if (it != words.end()) {
                    res.push_back(*it);
                    words.erase(temp);
                }
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        for (auto w : wordList)
            words.insert(w);
        if (words.find(endWord) == words.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int stepCount = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int z = 0; z < levelSize; z++) {
                
                string currWord = q.front(); q.pop();
               
                vector<string> neighbors = getNeighbors(currWord);

                for (string neighbor : neighbors) {
                    if (neighbor == endWord)
                        return stepCount + 1;
                    q.push(neighbor);
                }
            }
            stepCount++;
        }
        return 0;
    }
};