class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums,vector<int>& cur, int k){
        if(k==nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[k]);
        backtrack(nums, cur, k+1);
        cur.pop_back();
        while(nums[k] == nums[k+1]){
            k++;
        }
        backtrack(nums, cur, k+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        backtrack(nums, cur, 0);            
        return res;
    }
};
