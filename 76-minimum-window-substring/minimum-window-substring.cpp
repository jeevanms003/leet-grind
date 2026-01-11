class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;

        int left = 0, right = 0;
        int required = t.size();
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            if (freq[s[right]] > 0)
                required--;
            freq[s[right]]--;
            right++;

            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    required++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
