/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* copied = new Node(head->val);
        Node* curr1 = copied,* curr2 = head;
        unordered_map<Node*, Node*> hash;
        //copy next
        while(curr2){
            curr1->val = curr2->val;
            hash[curr2] = curr1;
            if(curr2->next) curr1->next = new Node(0);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        //copy random
        curr1 = copied, curr2 = head;
        while(curr2){
            curr1->random = hash[curr2->random];
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return copied;
    }
};
