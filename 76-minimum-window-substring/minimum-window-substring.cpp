class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // store frequency of t
        for(char c : t) mp[c]++;

        int left = 0, right = 0;
        int count = t.size();   // total chars needed
        int minLen = INT_MAX, start = 0;

        while(right < s.size()) {
            // if current char is needed
            if(mp[s[right]] > 0) count--;

            mp[s[right]]--;  // include char
            right++;

            // when all characters matched
            while(count == 0) {
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                mp[s[left]]++;  // remove char

                if(mp[s[left]] > 0) count++;  // needed again
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};