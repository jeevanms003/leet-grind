class WordDictionary {
    struct TrieNode {
        bool end = false;
        TrieNode* child[26] = {};
    };
    
    TrieNode* root;
    
    bool dfs(string &word, int idx, TrieNode* node) {
        if (!node) return false;
        if (idx == word.size()) return node->end;
        
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, idx + 1, node->child[i])) return true;
            }
            return false;
        } else {
            return dfs(word, idx + 1, node->child[c - 'a']);
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->child[c - 'a'])
                cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
