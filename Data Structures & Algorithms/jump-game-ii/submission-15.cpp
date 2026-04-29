class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n = nums.size();
        int step = 0;
        set<int> had;
        queue<int> qu;
        qu.push(0);
        while(!qu.empty()){
            int sz = qu.size();
            had.clear();
            for(int i=0;i<sz;i++){ 
                int cur = qu.front();
                qu.pop();
                for(int delta=1;delta<=nums[cur];delta++){
                    if(cur+delta == n-1) return step+1;
                    if(!had.count(cur+delta)){
                        qu.push(cur+delta);
                        had.insert(cur+delta);
                    }
                }
            }
            step++;
        }
    }
};
