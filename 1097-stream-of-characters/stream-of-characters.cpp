class StreamChecker {
    struct TrieNode {
        bool end = false;
        TrieNode* child[26] = {};
    };

    TrieNode* root;
    string stream;

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto &w : words) {
            TrieNode* cur = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int idx = w[i] - 'a';
                if (!cur->child[idx])
                    cur->child[idx] = new TrieNode();
                cur = cur->child[idx];
            }
            cur->end = true;
        }
    }

    bool query(char letter) {
        stream.push_back(letter);
        TrieNode* cur = root;

        for (int i = stream.size() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
            if (cur->end) return true;
        }
        return false;
    }
};
