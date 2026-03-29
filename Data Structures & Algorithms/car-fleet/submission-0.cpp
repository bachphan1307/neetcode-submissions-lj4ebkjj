class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carNum = position.size();
        if(carNum == 0) return 0;
        if(carNum == 1) return 1;
        vector<vector<int>> cars(carNum, vector<int>(2, 0));
        for(int i = 0; i< carNum; i++){
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        sort(cars.begin(),cars.end(), [](const auto a, const auto b){
            return a[0] < b[0];
        });

        stack<int> st;
        st.push(carNum-1);
        for(int i=carNum-1; i>=0; i--){
            double tochase = (double)(target - cars[st.top()][0]) / (cars[st.top()][1]);
            double chase = (double)(target - cars[i][0]) / (cars[i][1]);
            if(chase>tochase){
                st.push(i);
            }
        }
        return st.size();
    }
};
