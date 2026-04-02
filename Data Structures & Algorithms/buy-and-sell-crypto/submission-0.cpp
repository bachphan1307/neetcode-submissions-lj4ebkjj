class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int l = 0, r = 1;
        int max = 0;
        while(r<=n-1){
            int fluc = prices[r] - prices[l];
            if(fluc > max) max = fluc;
            if(fluc <= 0){
                l = r;
                r ++ ;
            }
            else{
                r ++;
            }
        }
        return max;
    }
};
