class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>m;
        for(string word:strs){
            string str = word;
            sort(str.begin(),str.end());
            m[str].push_back(word);
        }
        for(const auto& pair : m){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
