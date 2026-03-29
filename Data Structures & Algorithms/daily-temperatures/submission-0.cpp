class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len,0);
        stack<int>  st;
        for(int i=len-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                ans[i] = 0;
                continue;
            }
            else{
                while(temperatures[i] >= temperatures[st.top()]){
                    st.pop();
                    if(st.empty()){
                        st.push(i);
                        ans[i] = 0;
                        break;
                    }
                    else if(temperatures[i] < temperatures[st.top()]){
                        ans[i] = st.top() - i;
                        st.push(i);
                        break;
                    }
                }
                if(temperatures[i] < temperatures[st.top()]){
                        ans[i] = st.top() - i;
                        st.push(i);
                }
            }
            
        }
        return ans;
    }
};
