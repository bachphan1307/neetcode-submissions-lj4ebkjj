class Solution {
public:
    vector<vector<int>> res;
    void backtrack(const vector<int>& candidates, const int target, vector<int>& cur, int index, int sum){
        if(sum == target){
            res.push_back(cur);
            return;
        }
        if(sum>target || index>candidates.size()-1){
            return;
        }
        cur.push_back(candidates[index]);
        backtrack(candidates, target, cur, index+1, sum+candidates[index]);
        cur.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        backtrack(candidates, target, cur, index+1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, target, cur, 0,0);
        return res;
    }
};
