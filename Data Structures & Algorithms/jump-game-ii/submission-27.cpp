class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n = nums.size();
        int step = 0;
        int l = 0;
        int r = 0;
        while(r<n-1){
            int mx=0;
            for(int i=l;i<=r;i++){
                mx=max(mx,i+nums[i]);
            }
            l=r+1;
            r=mx;
            step++;
        }
        return step;
    }
};
