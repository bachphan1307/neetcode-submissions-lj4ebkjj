class Solution {
public:
    vector<string> res;
    void backtrack(int n, string cur, int open, int close){
        if(open == n && close == n){
            res.push_back(cur);
            return;
        }
        if(close>n||open>n||close>open) return;
        cur.append("(");
        backtrack(n, cur, open+1, close);
        cur.back() = ')';
        backtrack(n, cur, open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        backtrack(n, cur, 0,0);
        return res;
    }
};
