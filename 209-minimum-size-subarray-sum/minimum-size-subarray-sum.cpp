class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;

        int sum = 0;
    int minlen = INT_MAX;
        for (int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            while(sum >= target)
            {
                int len = i-left +1;
                minlen = min(minlen,len);
                sum = sum -nums[left];
                left++;
            }

        }

        if (minlen == INT_MAX )
        {
            return 0;
        }

        return minlen;
    }
};