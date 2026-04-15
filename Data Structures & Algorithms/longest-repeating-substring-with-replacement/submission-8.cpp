class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int left = 0, ans = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            counts[s[right] - 'A']++;
            
            // Cập nhật lại max_count chính xác tuyệt đối trong cửa sổ hiện tại
            int current_max = 0;
            for (int i = 0; i < 26; ++i) {
                current_max = max(current_max, counts[i]);
            }
            
            // Kiểm tra tính hợp lệ
            while ((right - left + 1) - current_max > k) {
                counts[s[left] - 'A']--;
                left++;
                
                // Sau khi giảm counts[s[left]], ta phải tìm lại current_max mới
                current_max = 0;
                for (int i = 0; i < 26; ++i) {
                    current_max = max(current_max, counts[i]);
                }
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};