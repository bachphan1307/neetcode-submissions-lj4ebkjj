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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 1;
        ListNode* curr = head;
        while(curr->next){
            curr = curr->next;
            sz++;
        }
        int target = sz - n - 1;
        if(target == -1) return head->next;
        curr = head;
        for(int i=0; i<target; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};
