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
    ListNode* merge(ListNode* one, ListNode* two){
        ListNode* cur1 = one,* cur2 = two;
        ListNode* ans = new ListNode(),* cur=ans;
        while(cur1 || cur2){
            int val1 = (cur1 == nullptr)?1001:cur1->val;
            int val2 = (cur2 == nullptr)?1001:cur2->val;
            if(val1<val2){
                cur->next = new ListNode(val1);
                cur = cur->next;
                if(cur1) cur1 = cur1->next;
            }else{
                cur->next = new ListNode(val2);
                cur = cur->next;
                if(cur2) cur2 = cur2->next;
            }
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        vector<ListNode*> after;
        while(lists.size() > 1){
            after = {};
            int n = lists.size();
            for(int i=0; i<n; i+=2){
                ListNode* one = lists[i];
                ListNode* two = (i+1<n) ? lists[i+1]:nullptr;
                ListNode* mer = merge(one,two);
                after.push_back(mer);
            }
            lists = after;
        }
        return lists[0];
    }
};
