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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr ;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        unordered_map <int,int> mp ;
        for (int x : arr)
        {
            mp[x]++;
        }
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        for(int x : arr)
        {
            if(mp[x] == 1)
            {
                temp->next = new ListNode(x);
            temp = temp->next;
            }
        }
        return dummy->next;
    }
};