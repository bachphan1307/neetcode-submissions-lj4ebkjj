class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashmap;
        if (s.size() != t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            hashmap[s[i]] ++;
            hashmap[t[i]] --;
        }
        for(auto const& [key,value]: hashmap){
            if(value != 0){
                return false;
            }
        }
        return true;
    }
};
