class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;

        for (char c : s)
            cnt[c]++;

        int need = n / 4;
        if (cnt['Q'] == need && cnt['W'] == need &&
            cnt['E'] == need && cnt['R'] == need)
            return 0;

        int left = 0, ans = n;

        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;

            while (left < n &&
                   cnt['Q'] <= need &&
                   cnt['W'] <= need &&
                   cnt['E'] <= need &&
                   cnt['R'] <= need) {
                ans = min(ans, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};
