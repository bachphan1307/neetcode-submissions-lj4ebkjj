class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] <= nums[n-1]) return nums[0];
        auto myabs = [](int a, int b){
            return a>b ? (a-b):(b-a);
        };
        int l = 0;
        int r = n-1;
        int m;

        while(r-l > 1){
            m = l + (r - l)/2;
            int dl = myabs(nums[m], nums[l]);
            int dr = myabs(nums[r], nums[m]);
            if(dl > dr) r = m;
            else l = m;
        }
        return nums[r];
    }
};
