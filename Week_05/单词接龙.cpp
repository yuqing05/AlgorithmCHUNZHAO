class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), beginSet, endSet, toolSet;
        if (beginWord.size() != endWord.size() || !dict.count(endWord)) {
            return 0;
        }
        int step = 0;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            step++;
            toolSet.clear();
            for (auto word : beginSet) {
                for (int i = 0;i < word.size();i++) {
                    char original = word[i];
                    for (auto ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) {
                            continue;
                        }
                        word[i] = ch;
                        if (endSet.count(word)) {
                            return step + 1;
                        }
                        if (dict.count(word) && !toolSet.count(word)) {
                            dict.erase(word);
                            toolSet.insert(word);
                        }
                        
                    }
                    word[i] = original;
                }
            }
            beginSet = toolSet;
        }
        return 0;
    }
};