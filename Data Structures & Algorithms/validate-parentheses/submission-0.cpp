class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        unordered_map<char,char> close = {{'(',')'},{'[',']'},{'{','}'}};

        stk.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i] == close[stk.back()]){
                stk.pop_back();                continue;
            }
            stk.push_back(s[i]);
        }
        return stk.empty();
    }
};
