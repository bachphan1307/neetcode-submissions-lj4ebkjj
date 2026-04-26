class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& cur, int index) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Optimization: If the number is greater than the remaining target, 
            // no need to check further because the array is sorted.
            if (candidates[i] > target) break;

            // DUPLICATE HANDLING:
            // If this element is the same as the one before it (and not the start of our loop),
            // we've already explored all unique combinations starting with this value.
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            cur.push_back(candidates[i]);
            // index + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i], res, cur, i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Crucial for duplicate handling
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, target, res, cur, 0);
        return res;
    }
};