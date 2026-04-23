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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        qu.push(root);
        while(!qu.empty()){
            vector<TreeNode*> stoNode;
            vector<int> sto;
            while(!qu.empty()){
                TreeNode* pop = qu.front();
                qu.pop();
                if(pop)stoNode.push_back(pop);
                if(pop)sto.push_back(pop->val);
            }
            ans.push_back(sto);
            for(TreeNode* node: stoNode){
                if(node->left)qu.push(node->left);
                if(node->right)qu.push(node->right);
            }
        }
        return ans;
    }
};
