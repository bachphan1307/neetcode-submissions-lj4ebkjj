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
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        int mx = 1;
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            if(cur.first->left) st.push({cur.first->left,cur.second+1}),mx=max(mx,cur.second+1);
            if(cur.first->right) st.push({cur.first->right,cur.second+1}),mx=max(mx,cur.second+1);
        }
        return mx;
    }
};
