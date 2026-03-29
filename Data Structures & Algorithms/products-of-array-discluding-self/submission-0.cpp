class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();

        int ltr[len];
        int rtl[len];

        ltr[0]       = 1;
        rtl[len - 1] = 1;


        for(int i=1;i<len;i++){
            ltr[i]       = ltr[i-1]*nums[i-1];
            rtl[len-1-i] = rtl[len-i]*nums[len-i];
        }

        for(int i = 0; i<len;i++){
            res.push_back(ltr[i] * rtl[i]);
        }
        return res;
    }
};
