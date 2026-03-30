class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int target = abs(nums[i]) - 1;
            if(nums[target] < 0) return abs(nums[i]);
            else nums[target]*=-1; 
        }
    }
};
