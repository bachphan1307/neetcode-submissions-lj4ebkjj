class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int up = 0;
        int down = ROWS - 1;
        int row;

        while (up <= down){
            row = up + (down - up)/2;
            if(matrix[row][0] > target) down = row - 1;
            else if(matrix[row][COLS - 1] < target) up = row + 1;
            else break;
        }

        int left = 0;
        int right = COLS - 1;
        int mid;

        while(left <= right){
            mid = left + (right - left) / 2;
            int val = matrix[row][mid];
            if(val == target) return true;
            else if(val > target) right = mid - 1;
            else if(val < target) left = mid + 1;
        }

        return false;

    }
};
