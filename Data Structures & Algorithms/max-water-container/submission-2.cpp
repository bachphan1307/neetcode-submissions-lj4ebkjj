class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int m = 0;
        while (i<j){
            int v = (j-i)*min(heights[i],heights[j]);
            if(v > m){
                m = v;
            }
            if(heights[i]<heights[j]) i++;
            else j--; 
        }
        return m;
    }
};
