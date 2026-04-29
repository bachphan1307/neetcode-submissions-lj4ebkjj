class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(dp[i]==true){
                for(int delta=1;delta<=nums[i];delta++){
                    dp[i+delta] = true;
                }
            }
        }
        return dp[n-1];
    }
};
