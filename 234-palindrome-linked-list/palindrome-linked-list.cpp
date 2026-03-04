class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> arr;
        ListNode* temp = head;

        // store values in array
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        // check palindrome
        while(i < j) {
            if(arr[i] != arr[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};