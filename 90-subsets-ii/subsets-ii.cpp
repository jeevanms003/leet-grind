class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans)
    {
        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++)
        {
            // skip duplicates
            if(i > index && nums[i] == nums[i-1])
                continue;

            temp.push_back(nums[i]);           // take element
            solve(i + 1, nums, temp, ans);     // recurse
            temp.pop_back();                   // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end()); // important

        solve(0, nums, temp, ans);
        return ans;
    }
};