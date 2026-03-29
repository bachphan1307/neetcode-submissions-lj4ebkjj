class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet{nums.begin(), nums.end()};
        int max = 0;
        for(int num: numSet){
            if(numSet.count(num-1) == 0){
                int len = 1;
                while(numSet.count(num+1) == 1){
                    len ++;
                    num ++;
                }
                if(len>max) max = len;
            }
        }
        return max;
    }
};
