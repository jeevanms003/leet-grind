class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto &q : queries) {
            int i = 0;
            bool ok = true;
            for (char c : q) {
                if (i < pattern.size() && c == pattern[i]) {
                    i++;
                } else if (isupper(c)) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok && i == pattern.size());
        }
        return ans;
    }
};
