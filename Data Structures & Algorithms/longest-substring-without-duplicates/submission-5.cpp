class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int max = 1;
        unordered_map<char, int> hmap;
        for(int i=0; i<n; i++){
            hmap[s[i]] = 0;
        }
        int l = 0;
        int r = 1;
        hmap[s[l]] += 1;
        hmap[s[r]] += 1;

        while(r<=n-1){
            if(hmap[s[l]] == 1 && hmap[s[r]] == 1){
                r++;
                hmap[s[r]] += 1;
                if(r-l>max) max = r-l;
            }else{
                hmap[s[l]] -= 1;
                l++;
            }
        }



        return max;
    }
};
