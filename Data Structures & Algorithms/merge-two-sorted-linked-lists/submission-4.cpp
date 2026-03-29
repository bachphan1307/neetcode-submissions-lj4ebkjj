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
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* merged = new ListNode();
        ListNode* curr = merged;
        while(head1 != nullptr && head2 != nullptr){
            int val1 = head1->val;
            int val2 = head2->val;
            if(val1 > val2){
                curr->next = new ListNode(val2);
                head2 = head2->next;
            }else{
                curr->next = new ListNode(val1);
                head1 = head1->next;
            }
            curr = curr->next;
        }
        curr->next = (head1==nullptr)? head2:head1;
        return merged->next;
    }
};
