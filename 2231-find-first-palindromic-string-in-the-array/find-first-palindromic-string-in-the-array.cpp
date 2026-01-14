class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &w : words)
        {
            if (w.size() == 1) return w;
            int l = 0,r = w.size() -1;
            bool ok = true;
            while (l<r)
            {
                if (w[l++] != w[r--])
                {
                    ok = false;
                    break;
                }
                
            }
            if(ok == true)
                {
                    return w;
                }
        }
        return "";
    }
};