class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n;
        for(int i=n-2;i>=0;i--){
            if(i+1+nums[i] >= target){
                target = i+1;
            }
        }
        if(target == 1) return true;
        return false;
    }
};
