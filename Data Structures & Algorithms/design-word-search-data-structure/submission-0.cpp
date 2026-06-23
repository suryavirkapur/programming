class WordDictionary {
   private:
    int frequency = 0;
    bool word = false;
    unordered_map<char, WordDictionary*> children;

   public:
    WordDictionary() {}

    void addWord(string word) {
        WordDictionary* node = this;

        for (char c : word) {
            if (!node->children.count(c)) node->children.insert({c, new WordDictionary()});
            node = node->children[c];
            node->frequency++;
        }
        node->word = true;
    }

    bool backtrack(string word, int index, WordDictionary* root) {
        WordDictionary* node = root;
        int n = word.size();

        for (int i = index; i < n; i++) {
            char c = word[i];
            if (c == '.') {
                for (auto [k,v] : node->children) {
                    if (backtrack(word,i+1,v)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                auto it = node->children.find(c);
                if (it == node->children.end()) return false;
                node = it->second;
            }
        }

        return node->word;
      
    }

    bool search(string word) {
        WordDictionary* node = this;
        return backtrack(word, 0, node);
    }
};
