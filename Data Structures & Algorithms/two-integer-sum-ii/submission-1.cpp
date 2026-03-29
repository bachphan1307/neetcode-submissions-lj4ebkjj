class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while(l < r && numbers[l] + numbers[r] != target){
            while(numbers[l] + numbers[r] < target) l++;
            while(numbers[l] + numbers[r] > target) r--;

        }
        return {l+1,r+1};
    }
};
