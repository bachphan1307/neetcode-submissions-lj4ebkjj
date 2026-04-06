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
    ListNode* next_k(ListNode* head, int k){
        ListNode* cur = head;
        while(--k){
            cur = cur->next;
            if(!cur) return nullptr;
        }
        return cur;
    }
    void reverse(ListNode* start, ListNode* end){
        //reverse Nodes from start to end 
        ListNode* cur = start->next, * prev = start;
        while(prev!=end){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* fur = next_k(cur,k),* furfur;
        ListNode* nxt;
        if(fur) head = fur;
        else return head;

        while(1){
            if(fur->next)furfur = next_k(fur->next, k);
            else furfur = nullptr;
            ListNode* tmp = fur->next;
            reverse(cur,fur);
            if(furfur) cur->next = furfur;
            else{
                cur->next = tmp;
                return head;
            }
            cur = tmp;
            fur = next_k(cur,k);
        }
    }
};
