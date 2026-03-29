class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1) return 0;
        int l = 0;
        int r = height.size() - 1;
        int ml = height[l];
        int mr = height[r];

        int volume = 0;

        while(l < r){
            if(height[l]<=height[r]){
                l++;
                if(ml - height[l] > 0) volume += ml - height[l];
                if(height[l] > ml) ml = height[l];
            }
            else{ 
                r--;
                if(mr - height[r] > 0) volume += mr - height[r];
                if(height[r] > mr) mr = height[r];
                
            }

        }
        return volume;
    }
};
