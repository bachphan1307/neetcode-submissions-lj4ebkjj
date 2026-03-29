class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sắp xếp để dễ dàng loại bỏ trùng lặp
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // CHUẨN HÓA 1: Bỏ qua số thứ nhất nếu nó trùng với số trước đó
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // CHUẨN HÓA 2: Bỏ qua các giá trị trùng lặp của số thứ hai
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // CHUẨN HÓA 3: Bỏ qua các giá trị trùng lặp của số thứ ba
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Sau khi bỏ qua trùng lặp, vẫn phải dịch chuyển con trỏ 1 lần nữa
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Tổng âm -> cần số lớn hơn -> tăng left
                } 
                else {
                    right--; // Tổng dương -> cần số nhỏ hơn -> giảm right
                }
            }
        }
        return ans;
    }
};