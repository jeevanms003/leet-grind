class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];   // best (lowest) price to buy
        int maxProfit = 0;          // best profit so far

        for (int i = 1; i < prices.size(); i++) {
            // selling today gives profit?
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);

            // update minPrice (better day to buy)
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
