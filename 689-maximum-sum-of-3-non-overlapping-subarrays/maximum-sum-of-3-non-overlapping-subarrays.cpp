class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n - k + 1;

        vector<int> w(m);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (i >= k) cur -= nums[i - k];
            if (i >= k - 1) w[i - k + 1] = cur;
        }

        vector<int> left(m), right(m);

        left[0] = 0;
        for (int i = 1; i < m; i++)
            left[i] = (w[i] > w[left[i - 1]]) ? i : left[i - 1];

        right[m - 1] = m - 1;
        for (int i = m - 2; i >= 0; i--)
            right[i] = (w[i] >= w[right[i + 1]]) ? i : right[i + 1];

        vector<int> res(3);
        int best = 0;

        for (int j = k; j < m - k; j++) {
            int i = left[j - k];
            int l = right[j + k];
            int total = w[i] + w[j] + w[l];
            if (total > best) {
                best = total;
                res = {i, j, l};
            }
        }

        return res;
    }
};
