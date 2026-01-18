class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);
        int cur = 0;
        bool down = false;

        for (char c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1)
                down = !down;
            cur += down ? 1 : -1;
        }

        string res;
        for (string &r : rows)
            res += r;

        return res;
    }
};
