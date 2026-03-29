class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int,int>> st;
        int n = heights.size();
        for(int i=0; i<n; i++){
            int start = i;
            while(!st.empty() && heights[i] < st.top().second){
                maxArea = max(st.top().second*(i-st.top().first), maxArea);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        int s = st.size();
        int h = heights.size();
        for(int i=0; i<s; i++){
            maxArea = max(   st.top().second *(h-st.top().first) , maxArea);
            st.pop();
        }
        return maxArea;
    }
};
