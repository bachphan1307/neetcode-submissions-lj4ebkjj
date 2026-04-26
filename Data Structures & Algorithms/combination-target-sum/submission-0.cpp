class Solution {
public:
    vector<vector<int>> res;

    void backtrack(const vector<int>& nums, int target, vector<int>& cur, int sum, int start) {
        // Base Case: Success
        if (sum == target) {
            res.push_back(cur);
            return;
        }

        // Base Case: Exceeded target
        if (sum > target) {
            return;
        }

        // Iterate through candidates starting from 'start' to avoid duplicates
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            
            // Note: we pass 'i' as the new 'start' because we can reuse the same element
            backtrack(nums, target, cur, sum + nums[i], i); 
            
            // Backtrack: remove the last element before the next iteration
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, cur, 0, 0);
        return res;
    }
};