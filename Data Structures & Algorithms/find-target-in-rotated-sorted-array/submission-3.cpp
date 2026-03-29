class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int gl = l;
        int gr = r;

        if(nums[r] < nums[l]){
            int m;
            while(r - l > 1){
                m = l + (r-l)/2;
                int dl = abs(nums[m] - nums[l]);
                int dr = abs(nums[r] - nums[m]);
                if(dr > dl) l = m;
                else r = m;
            }
            if(target >= nums[r] && target <= nums[n-1]) gl = r;
            else gr = r - 1;
        }

        while(gl <= gr){
            int m = gl + (gr - gl) / 2;
            if(nums[m] == target) return m;
            else if(target > nums[m]) gl = m + 1;
            else gr = m - 1;
        }
        return -1;
    }
};
