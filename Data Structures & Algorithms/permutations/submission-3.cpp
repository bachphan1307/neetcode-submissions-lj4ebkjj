class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int start) {
        // Base case: if we've reached the end, we've found a valid permutation
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // 1. Swap the current element with the element at the 'start' index
            swap(nums[start], nums[i]);
            
            // 2. Recurse for the next index
            backtrack(nums, start + 1);
            
            // 3. Backtrack: Swap back to restore the original order
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};