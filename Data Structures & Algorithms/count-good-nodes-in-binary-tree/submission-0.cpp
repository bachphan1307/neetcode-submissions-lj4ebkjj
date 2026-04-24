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
    int res = 1;
    void getgoodNodes(TreeNode* root, int mx){
        if(!root) return;
        TreeNode* lft = root->left;
        TreeNode* rt = root->right;
        if(lft&& lft->val >= mx) res++;
        if(rt&& rt->val >= mx) res++;
        if(lft)getgoodNodes(lft, max(mx,lft->val));
        if(rt) getgoodNodes(rt, max(mx,rt->val));
    }
    int goodNodes(TreeNode* root) {
        getgoodNodes(root, root->val);
        return res;
    }
};
