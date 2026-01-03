class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            int digits = 0;
            while (x) {
                digits++;
                x /= 10;
            }
            if (digits % 2 == 0) count++;
        }
        return count;
    }
};