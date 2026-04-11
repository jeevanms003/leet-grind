class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m == 0) return 0;

        for(int i = 0; i <= n - m; i++) {
            int j = 0;

            // match substring
            while(j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if(j == m) return i; // full match found
        }

        return -1; // not found
    }
};