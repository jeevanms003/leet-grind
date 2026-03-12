class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 2)
        {
            return abs(nums[0] - nums[1]);
        }
        sort(nums.begin(), nums.end());
        int gap = 0;
        for(int i = 1 ; i <nums.size();i++)
        {
            int xgap =  abs( nums[i] - nums[i-1]);
            gap = max(xgap,gap);
        }
        return gap;
    }
};