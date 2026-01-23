class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, len = 0;
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaces = maxWidth - len;
                int even = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(even + (extra-- > 0), ' ');
                    }
                }
            }

            res.push_back(line);
            i = j;
        }
        return res;
    }
};
