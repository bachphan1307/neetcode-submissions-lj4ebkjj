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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }        
        //reversing second half
        ListNode *curr = slow->next, *prev = nullptr, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // merging first and second half
        slow->next = nullptr;
        ListNode *first = head, *second = prev;
        while(second){
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1, second = tmp2;
        }

    }
};
