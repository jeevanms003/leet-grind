class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(10);
        string word;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                int idx = word.back() - '0';
                word.pop_back();
                v[idx] = word;
                word.clear();
            } else {
                word += s[i];
            }
        }
        string res;
        for (int i = 1; i < 10; i++) {
            if (v[i].empty()) break;
            if (!res.empty()) res += " ";
            res += v[i];
        }
        return res;
    }
};