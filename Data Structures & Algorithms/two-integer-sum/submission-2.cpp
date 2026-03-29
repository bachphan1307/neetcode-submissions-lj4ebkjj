class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Kiểm tra xem số còn lại đã có trong map chưa
            if (hashmap.count(complement)) {
                // TÌM THẤY LÀ TRẢ VỀ LUÔN -> Tiết kiệm bộ nhớ và thời gian
                return {hashmap[complement], i};
            }
            
            // Nếu chưa thấy thì mới thêm số hiện tại vào map
            hashmap[nums[i]] = i;
        }
        
        return {}; // Trường hợp không tìm thấy (theo đề bài thì luôn tìm thấy)
    }
};