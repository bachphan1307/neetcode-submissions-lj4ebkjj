/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int equivalent = 1;
    void cpr(TreeNode* p, TreeNode* q){
        if((!p&&q)||(p&&!q)||(p->val != q->val)){
            equivalent = 0;
        }
        if(p&&q){
            if(((p->left))||(q->left))cpr(p->left,q->left);
            if(((p->right))||(q->right))cpr(p->right,q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        cpr(p,q);
        if(!equivalent)return false;
        return true;
    }
};
