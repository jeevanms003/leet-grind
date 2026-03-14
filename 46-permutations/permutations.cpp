class Solution {
public:

    void solve(vector<int>& nums, vector<int>& temp, 
               vector<vector<int>>& ans, vector<int>& used)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;

            used[i] = 1;
            temp.push_back(nums[i]);

            solve(nums, temp, ans, used);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(),0);

        solve(nums, temp, ans, used);

        return ans;
    }
};