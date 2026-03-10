class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> it (nums1.begin(),nums1.end());
        vector<int> result;
        for(int num : nums2) {
            if(it.count(num)) {
                result.push_back(num);
                it.erase(num);   // remove to ensure uniqueness
            }
        }
        return result;


    }
};