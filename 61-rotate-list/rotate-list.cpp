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
    ListNode* rotateRight(ListNode* head, int k) {
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
        int n = arr.size();
        k = k % n;
        k = abs(n -k)  ;
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin(),arr.end());
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