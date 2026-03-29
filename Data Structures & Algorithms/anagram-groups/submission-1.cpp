class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hmap;
        for(string str:strs){
            int n = 'z'-'a' + 1;
            int key[n] = {0};
            for(char c:str){
                key[c - 'a'] ++;
            }
            string k ="";
            for(int i=0;i<n;i++){
                k += to_string(key[i]) + "#";
            }
            hmap[k].push_back(str);

        }
        vector<vector<string>> res;
        for(auto element:hmap){
            res.push_back(element.second);
        }
        return res;
    }
};