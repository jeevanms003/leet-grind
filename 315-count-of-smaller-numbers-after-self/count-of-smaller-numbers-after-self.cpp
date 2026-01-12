class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }

    void mergeSort(vector<pair<int,int>>& arr, int l, int r, vector<int>& ans) {
        if (l >= r) return;

        int m = (l + r) / 2;
        mergeSort(arr, l, m, ans);
        mergeSort(arr, m + 1, r, ans);
        merge(arr, l, m, r, ans);
    }

    void merge(vector<pair<int,int>>& arr, int l, int m, int r, vector<int>& ans) {
        vector<pair<int,int>> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (arr[i].first <= arr[j].first) {
                ans[arr[i].second] += (j - m - 1);
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= m) {
            ans[arr[i].second] += (j - m - 1);
            temp.push_back(arr[i++]);
        }

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];
    }
};