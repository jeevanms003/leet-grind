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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * temp = head;
        vector<int> arr;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        ListNode * dummy = new ListNode(0);
        temp = dummy;
        for(int x : arr)
        {
            if(x != val)
            {
                temp->next = new ListNode(x);
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};