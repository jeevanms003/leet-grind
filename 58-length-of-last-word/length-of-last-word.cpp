class Solution {
public:
    int lengthOfLastWord(string s) {
        int b = s.size() -1;
        int e = s.size() -1;
        while (b >= 0 && s[b] == ' ')
        {
            b--;
        }
        e= b-1;
        while(e >= 0 && s[e] != ' ')
        {
            e--;
        }
        return b-e;
    }
};