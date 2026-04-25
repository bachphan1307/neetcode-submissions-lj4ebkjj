class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int level, vector<int> nums, vector<int> cur){
        if(level==nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[level]);
        backtrack(level+1,nums,cur);
        cur.pop_back();
        backtrack(level+1,nums,cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(0,nums,cur);
        return res;
    }
};
