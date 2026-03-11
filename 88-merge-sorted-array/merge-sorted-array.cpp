class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr;
        for(int i = 0 ; i <m ; i++)
        {
            arr.push_back(nums1[i]);
        }

        for(int x: nums2)
        {
            arr.push_back(x);
        }

        sort(arr.begin(),arr.end());
        for(int i = 0 ; i<nums1.size();i++)
        {
            nums1[i] = arr[i];
        }
        
    }
};