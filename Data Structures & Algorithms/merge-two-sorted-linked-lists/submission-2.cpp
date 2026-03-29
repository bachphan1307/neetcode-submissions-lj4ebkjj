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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* merged = new ListNode();
        ListNode* curr = merged;
        while(head1 != nullptr || head2 != nullptr){
            int val1 = (head1 == nullptr) ? INT_MAX:head1->val;
            int val2 = (head2 == nullptr) ? INT_MAX:head2->val;
            if(val1 > val2){
                curr->val = val2;
                head2 = head2->next;
            }else{
                curr->val = val1;
                head1 = head1->next;
            }
            if(!(head1 == nullptr && head2 == nullptr)){
            curr->next = new ListNode();
            curr = curr->next;
            }
        }
        return merged;
    }
};
