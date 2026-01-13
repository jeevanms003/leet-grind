class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>> dq;
        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0], y = p[1];

            while (!dq.empty() && x - dq.front().first > k)
                dq.pop_front();

            if (!dq.empty())
                ans = max(ans, y + x + dq.front().second);

            int val = y - x;
            while (!dq.empty() && dq.back().second <= val)
                dq.pop_back();

            dq.push_back({x, val});
        }
        return ans;
    }
};