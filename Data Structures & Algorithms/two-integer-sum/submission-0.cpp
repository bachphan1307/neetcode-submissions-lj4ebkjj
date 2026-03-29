class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        int first, sec;
        for (int i=0;i<nums.size();i++){
            if(hashmap.count(target-nums[i]) != 0){
                first = hashmap[target-nums[i]];
                sec = i;
            }

            if(hashmap.count(nums[i]) == 0){
                hashmap[nums[i]] = i;
            }
            
        }
        if(first>sec){
            return {sec,first};
        }
        else{
            return {first,sec};
        }
    }
};
