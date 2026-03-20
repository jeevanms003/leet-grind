class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0,xor2 = 0;
        for(int x = 0 ; x<= nums.size();x++)
        {
            xor1^=x;
        }
        for(int x: nums)
        {
            xor2 ^= x;
        }
        return xor1^xor2;
    }
};