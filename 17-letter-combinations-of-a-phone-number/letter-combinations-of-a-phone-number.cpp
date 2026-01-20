class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> res;
        string cur;
        dfs(digits, 0, mp, cur, res);
        return res;
    }
    
    void dfs(string &digits, int idx, vector<string> &mp,
             string &cur, vector<string> &res) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : mp[digits[idx] - '0']) {
            cur.push_back(c);
            dfs(digits, idx + 1, mp, cur, res);
            cur.pop_back();
        }
    }
};
