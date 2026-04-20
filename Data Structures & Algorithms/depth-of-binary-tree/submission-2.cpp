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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int mx = 1;
        root->val = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){
                cur->left->val = cur->val+1;
                mx = max(mx, cur->left->val);
                q.push(cur->left);
            }
            if(cur->right){
                cur->right->val = cur->val+1;
                mx = max(mx, cur->right->val);
                q.push(cur->right);
            }
        }
        return mx;
    }
};
