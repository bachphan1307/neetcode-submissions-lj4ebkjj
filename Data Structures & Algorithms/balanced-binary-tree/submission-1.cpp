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
    int balanced = 1;
    int nodeHeight(TreeNode* root){
        if(!root) return 0;
        int lft = nodeHeight(root->left);
        int rt = nodeHeight(root->right);
        if(abs(lft-rt)>1) balanced = 0;
        return 1+max(lft,rt);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        nodeHeight(root);
        if(!balanced) return false;
        return true;
    }
};
