class Solution {
public:
    int expand(string &s, int left, int right) {
        int count = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;   // found a palindrome
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int total = 0;

        for(int i = 0; i < s.size(); i++) {
            // odd length palindromes
            total += expand(s, i, i);

            // even length palindromes
            total += expand(s, i, i + 1);
        }

        return total;
    }
};