class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;  // ceil division
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                ans = mid;        // possible answer
                right = mid - 1;  // try smaller speed
            } else {
                left = mid + 1;   // need more speed
            }
        }

        return ans;
    }
};