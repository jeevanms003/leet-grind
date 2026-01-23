class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;

        vector<int> lps(t.size(), 0);
        for (int i = 1; i < t.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && t[i] != t[j]) {
                j = lps[j - 1];
            }
            if (t[i] == t[j]) j++;
            lps[i] = j;
        }

        int palLen = lps.back();
        return rev.substr(0, s.size() - palLen) + s;
    }
};
