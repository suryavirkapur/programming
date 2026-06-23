class PrefixTree {
private: 
    unordered_map<char, PrefixTree*> children;
    int freq = 0;
    bool endsHere = false;
    
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        PrefixTree *node = this;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (!node->children.count(c)) {
                node->children.insert({c, new PrefixTree()});
            }
            node = node->children[c];
            node->freq++;
            if (i == n-1) node->endsHere = true;
        }
    }
    
    bool search(string word) {
        PrefixTree* node = this;
        for (char c  : word) {
            auto it = node->children.find(c);
            if (it == node->children.end()) return false;
            node = it->second;
        }
        return node->endsHere;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for (char c  : prefix) {
            auto it = node->children.find(c);
            if (it ==  node->children.end()) return false;
            node = it->second;
        }
        return node-> freq > 0 ? true : false;
    }
};
