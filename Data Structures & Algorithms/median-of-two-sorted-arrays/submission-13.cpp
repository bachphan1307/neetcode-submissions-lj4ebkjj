class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        
        // Đảm bảo nums1 là mảng ngắn hơn để tối ưu log(min(a, b))
        if (a > b) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, r = a;
        int half = (a + b + 1) / 2; // Dùng +1 để xử lý cả trường hợp lẻ
        
        while (l <= r) {
            int m1 = l + (r - l) / 2; // Số phần tử lấy từ nums1
            int m2 = half - m1;       // Số phần tử lấy từ nums2
            
            // Lấy các giá trị biên (xử lý trường hợp m1, m2 bằng 0 hoặc tối đa)
            int v1l = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int v1r = (m1 == a) ? INT_MAX : nums1[m1];
            int v2l = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int v2r = (m2 == b) ? INT_MAX : nums2[m2];
            
            if (v1l <= v2r && v2l <= v1r) {
                // Đã tìm thấy điểm cắt đúng
                if ((a + b) % 2 == 0) {
                    return (max(v1l, v2l) + min(v1r, v2r)) / 2.0;
                } else {
                    return max(v1l, v2l);
                }
            } 
            else if (v1l > v2r) {
                r = m1 - 1; // Nhích sang trái
            } else {
                l = m1 + 1; // Nhích sang phải
            }
        }
        return 0.0;
    }
};