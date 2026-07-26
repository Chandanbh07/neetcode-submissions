class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mp;
        int n = position.size();
        int i = 0;
        stack<int> st;

        while(i<n){
            mp[position[i]] = speed[i];
            i++;
        }

        sort(position.begin(),position.end());

        i = n-1;
        while(i >= 0){
            if(st.empty()){
                st.push(i);
            }
            else{
                double t1 = (double) (target - position[i])/mp[position[i]];
                double t2 = (double) (target - position[st.top()])/mp[position[st.top()]];
                if(t1 > t2){
                    st.push(i);
                }
            }
            i--;
        }
        return st.size();
    }
};
