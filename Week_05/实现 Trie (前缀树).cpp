/*
 * @Author: your name
 * @Date: 2021-02-27 12:52:16
 * @LastEditTime: 2021-02-27 13:17:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Week_05/实现 Trie (前缀树).cpp
 */
class Trie {
private:
    Trie* next[26];
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto ch : word) {
            if (node->next[ch - 'a'] == nullptr) {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto ch : word) {
            if (node->next[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return node->isEnd;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto ch : prefix) {
            if (node->next[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return true;
    }
};
