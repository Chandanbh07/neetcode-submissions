class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i: nums){
            mp[i]++;
        }

        int maxlen=0;
        for(int i: nums){
            int len = 1;
            if(mp.find(i-1) == mp.end()){
                
                while(mp.count(i+1)){
                    i++;
                    len++;
                }
                
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};
