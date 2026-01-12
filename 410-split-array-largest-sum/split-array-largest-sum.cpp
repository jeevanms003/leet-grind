class Solution {
public:
    bool canSplit(vector<int>& nums, int m, long long maxSum) {
        long long cur = 0;
        int cnt = 1;
        for (int x : nums) {
            if (cur + x > maxSum) {
                cnt++;
                cur = x;
                if (cnt > m) return false;
            } else {
                cur += x;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = hi;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, m, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};