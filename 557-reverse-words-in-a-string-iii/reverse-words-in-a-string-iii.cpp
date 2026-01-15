class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int start = i;
            while (i < n && s[i] != ' ') i++;
            int end = i - 1;

            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            i++;
        }
        return s;
    }
};