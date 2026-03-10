class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        
        
        
        vector<int> pCount(26,0);
        vector<int> sCount(26,0);
        
        // frequency of p
        for(char c : p)
            pCount[c - 'a']++;
        
        int window = p.size();
        
        for(int i = 0; i < s.size(); i++) {
            
            sCount[s[i] - 'a']++;
            
            // maintain window size
            if(i >= window)
                sCount[s[i-window] - 'a']--;
            
            if(sCount == pCount)
                result.push_back(i - window + 1);
        }
        
        return result;
    }
};