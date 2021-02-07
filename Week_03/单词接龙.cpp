
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
// 
//     序列中第一个单词是 beginWord 。
//     序列中最后一个单词是 endWord 。
//     每次转换只能改变一个字母。
//     转换过程中的中间单词必须是字典 wordList 中的单词。
//
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
//
// 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// 输出：5
// 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> beginSet, endSet, toolSet;
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int path = 1;
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            toolSet.clear();
            for (auto word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    char originalChar = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == originalChar) {
                            continue;
                        }
                        word[i] = ch;
                        if (endSet.find(word) != endSet.end()) {
                            return path + 1;
                        }
                        if (words.find(word) != words.end()) {
                            
                            toolSet.insert(word);
                            words.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
            beginSet = toolSet;
            path++;
        }
        return 0;
        
    }
};