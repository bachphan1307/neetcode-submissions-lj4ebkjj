class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto isValid = [h](int k, vector<int>& piles){
            int hours = h;
            for(int i = 0; i< piles.size(); i++){
                int time = ceil(piles[i]/ (double)k);
                hours -= time;
                if(hours < 0) return false;
            }
            return true;
        };

        int N = piles.size();
        int max = 0;
        for(int i = 0;i < N; i++){
            if(piles[i] > max) max = piles[i];
        }
        int left = 1;
        int right = max;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(isValid(mid, piles)) right = mid - 1;
            else  left = mid + 1;
        }
        return left;
    }
};
