class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for(string tok: tokens){
            if(tok!="+"&&tok!="-"&&tok!="*"&&tok!="/") res.push(stoi(tok));
            else{
                int b = res.top();
                res.pop();
                int a = res.top();
                res.pop();
                if     (tok == "+") res.push(a+b);
                else if(tok == "-") res.push(a-b);
                else if(tok == "*") res.push(a*b);
                else if(tok == "/") res.push(a/b);
            }
        }
        return res.top();
    }
};
