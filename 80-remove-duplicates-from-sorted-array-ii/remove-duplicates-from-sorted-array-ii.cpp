class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_map<int,int> mp;
        vector<int> arr;

        for(int x : nums)
        {
            mp[x]++;

            if(mp[x] <= 2)
            {
                arr.push_back(x);
            }
        }

        for(int i = 0; i < arr.size(); i++)
        {
            nums[i] = arr[i];
        }

        return arr.size();
    }
};