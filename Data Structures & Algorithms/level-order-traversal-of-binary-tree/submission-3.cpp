class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        
        while (!qu.empty()) {
            // 1. Capture the current level size
            int levelSize = qu.size();
            vector<int> currentLevel;
            
            // 2. Only process 'levelSize' nodes
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                
                currentLevel.push_back(node->val);
                
                // 3. Push children directly back into the queue
                // They won't be processed until the NEXT iteration of the while loop
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            
            ans.push_back(currentLevel);
        }
        
        return ans;
    }
};