/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        vector<int> arr;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin() + left -1 ,arr.begin() + right );
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        for(int x : arr)
        {
            temp ->next = new ListNode(x);
            temp = temp->next;
        }
        return dummy->next;
        
    }
};