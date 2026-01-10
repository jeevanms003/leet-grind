class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long time = 0;
        for (int p : piles) {
            time += (p + k - 1) / k;
            if (time > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};