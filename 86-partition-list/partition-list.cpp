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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        vector<int> arr1;
        while(temp != NULL)
        {
            arr1.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> arr2;
        for (int y : arr1)
        {
            if(y < x)
            {
                arr2.push_back(y);
            }
        }
        for (int y : arr1)
        {
            if(y >= x)
            {
                arr2.push_back(y);
            }
        }
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        for(int y : arr2)
        {
            temp ->next = new ListNode(y);
            temp = temp->next;
        }
        return dummy->next;

    }
};