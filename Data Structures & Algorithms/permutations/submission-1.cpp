class Solution {
public:
    set<int> hash;
    vector<int> cur;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums){
        for(int num: nums){
            if(!hash.count(num)){
                hash.insert(num);
                cur.push_back(num);
                if(cur.size() == nums.size()){
                    res.push_back(cur);
                }
                else{
                    backtrack(nums);
                }
                cur.pop_back();
                hash.erase(num);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return res;
    }
};
