#include <unordered_map>
#include <string>


using std::string;
using std::unordered_map;

struct Trie {
    unordered_map<char, Trie*> children;
    int freq = 0;

    void insert(const string &word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children.emplace(c, new Trie{});
            }
            node = node->children[c];
            node->freq++;
        }
    }

    int query(const string &prefix) {
        Trie *node = this;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return 0;
            }
            node = node->children.at(c);
        }
        return node->freq;
    }
};
