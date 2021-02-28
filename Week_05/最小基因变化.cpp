/*
 * @Author: your name
 * @Date: 2021-02-27 22:19:57
 * @LastEditTime: 2021-02-27 22:20:05
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Week_05/最小基因变化.cpp
 */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end()), beginSet, endSet, toolSet;
        if (end.size() == 0 || !dict.count(end)) {
            return -1;
        }
        beginSet.insert(start);
        endSet.insert(end);
        int step = 0;

        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            step++;
            toolSet.clear();
            for (auto s : beginSet) {
                for (int i = 0; i < s.length(); i++) {
                    char original = s[i];
                    for (auto ch : "ACGT") {
                        if (ch == original) {continue;}
                        s[i] = ch;
                        if (endSet.count(s)) {
                            return step;
                        }
                        if (dict.count(s) && !toolSet.count(s)) {
                            toolSet.insert(s);
                            dict.erase(s);
                        }
                    }
                    s[i] = original;
                }
            }
            beginSet = toolSet;

        }
        return -1;

    }
};