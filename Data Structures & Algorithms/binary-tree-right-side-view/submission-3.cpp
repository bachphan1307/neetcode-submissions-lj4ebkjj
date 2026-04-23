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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qu;
        vector<int> rsv;
        qu.push(root);
        while(!qu.empty()){
            rsv.push_back((qu.front())->val);
            int sz = qu.size();
            for(int i=0;i<sz;i++){
                TreeNode* pop = qu.front();
                if(pop->right) qu.push(pop->right);
                if(pop->left) qu.push(pop->left);
                qu.pop();
            }
        }
        return rsv;
    }
};
