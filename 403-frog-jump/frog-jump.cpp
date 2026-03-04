class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        unordered_map<int, unordered_set<int>> mp;
        
        for(int stone : stones)
            mp[stone] = {};
        
        mp[0].insert(0);
        
        for(int stone : stones) {
            for(int jump : mp[stone]) {
                
                for(int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
                    
                    if(nextJump > 0 && mp.count(stone + nextJump)) {
                        mp[stone + nextJump].insert(nextJump);
                    }
                }
            }
        }
        
        return !mp[stones.back()].empty();
    }
};