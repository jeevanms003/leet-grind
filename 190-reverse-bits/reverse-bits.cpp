class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        for(int i = 0; i < 32; i++) {
            ans <<= 1;        // shift left
            ans |= (n & 1);   // add last bit of n
            n >>= 1;          // shift n right
        }
        
        return ans;
    }
};