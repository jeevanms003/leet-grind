class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int x : nums)
        {
            mp[x]++;

            if(mp[x] == nums.size()/3 +1)
            {
                ans.push_back(x);
            }
        }

        return ans;
    }
};