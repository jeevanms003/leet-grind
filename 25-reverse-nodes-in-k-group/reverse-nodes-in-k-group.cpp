class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<int> arr;
        ListNode* temp = head;

        // store all values in array
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // reverse every k group in array
        for(int i = 0; i + k <= arr.size(); i += k) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        // put values back into linked list
        temp = head;
        int i = 0;

        while(temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};