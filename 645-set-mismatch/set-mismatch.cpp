class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        for (int x : nums)
            count[x]++;

        int dup = -1, miss = -1;
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) dup = i;
            else if (count[i] == 0) miss = i;
        }

        return {dup, miss};
    }
};