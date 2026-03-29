class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        unordered_map<int,vector<int>> freq;
        for(int num: nums){
            cnt[num]++;
        }
        for(auto const& [num,f] : cnt){
            freq[f].push_back(num);
        }

        vector<int> res;
        for(int i=nums.size();i>=1;i--){
            for(int num: freq[i]){
                res.push_back(num);
                if(res.size() == k){
                    return res;
                }
            }
        }
    }
};
