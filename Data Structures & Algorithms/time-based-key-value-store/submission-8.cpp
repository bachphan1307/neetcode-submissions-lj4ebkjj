class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int n = store[key].size();
        string value;
        int l = 0;
        int r = n-1;
        if(n==0) return "";
        if(store[key][l].first > timestamp) return "";
        if(store[key][r].first <= timestamp) l = r;
        else{
        while(r - l > 1){
            int m = l + (r-l)/2;
            if(store[key][m].first > timestamp) r = m;
            else if(store[key][m].first < timestamp) l = m;
            else{
                l = m;
                break;
            }
        }
        }
        value = store[key][l].second;
        
        return value;
    }
};
