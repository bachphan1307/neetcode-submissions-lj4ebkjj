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
    bool hasCycle(ListNode* head) {
        int mark = 1001;
        while(head){
            if(head->val == mark) return true;
            if(!head->next) return false;
            head->val = mark;
            head = head->next;
        }
        return false;
    }
};
