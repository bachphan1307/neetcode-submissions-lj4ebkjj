class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums,vector<int>& cur,int idx){
        if (idx == nums.size()){
            res.push_back(cur);
            return;
        }

        backtrack(nums, cur, idx+1);
        cur.push_back(nums[idx]);
        backtrack(nums, cur, idx+1);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, cur,0);
        return res;
    }
};
