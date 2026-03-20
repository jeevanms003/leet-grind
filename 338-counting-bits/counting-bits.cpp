class Solution {
public:
int hammingWeight(int n) {
        int count = 0;
        
        while(n > 0) {
            if(n & 1) count++;
            n = n >> 1;
        }
        
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans( n+1,0);
        for(int i = 1 ; i <=n;i++)
        {
            ans[i] = hammingWeight(i);
        }
        return ans;
    }
};