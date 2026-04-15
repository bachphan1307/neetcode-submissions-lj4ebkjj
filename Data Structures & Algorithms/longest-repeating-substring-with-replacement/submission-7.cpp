class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0); // Đếm tần suất xuất hiện của 26 chữ cái
        int left = 0, max_count = 0, ans = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            // Cập nhật tần suất của ký tự bên phải
            max_count = max(max_count, ++counts[s[right] - 'A']);
            
            // Nếu (độ dài cửa sổ - số ký tự xuất hiện nhiều nhất) > k 
            // Nghĩa là số ký tự cần thay thế vượt quá k, ta phải thu hẹp cửa sổ bên trái
            while (right - left + 1 - max_count > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            
            // Cập nhật kết quả độ dài cửa sổ lớn nhất thỏa mãn
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};