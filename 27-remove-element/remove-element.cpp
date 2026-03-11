class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> arr ;
        for(int x : nums)
        {
            if(x != val){
            arr.push_back(x);}
        }
        for(int i = 0 ; i <arr.size(); i++)
        {
            nums[i] = arr[i];
        }
        return arr.size();
        
    }
};