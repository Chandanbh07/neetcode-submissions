class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mp;
        int n = position.size();
        int i = 0;

        while(i<n){
            mp[position[i]] = speed[i];
            i++;
        }

        sort(position.begin(),position.end());

        i = n-1;
        int fleet = 0;
        double lasttime = 0;
        while(i >= 0){
            double currtime = (double) (target - position[i]) / mp[position[i]];

            if(lasttime <  currtime){
                fleet++;
                lasttime = currtime;
            }
            i--;
        }
        return fleet;
    }
};
