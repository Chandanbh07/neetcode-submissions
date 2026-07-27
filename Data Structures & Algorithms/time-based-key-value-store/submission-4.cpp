class TimeMap {
public:
    unordered_map<string , vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        auto& v = mp[key];
        string ans= "";

        int st = 0;
        int end = v.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(v[mid].first <= timestamp){
                ans = v[mid].second;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};
