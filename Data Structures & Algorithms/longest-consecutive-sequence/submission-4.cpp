class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();

        int maxlen=0;
        for(int i: nums){
            int len = 1;
            if(!s.count(i-1)){
                int curr = i;
                while(s.count(curr+1)){
                    curr++;
                    len++;
                }
                
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};
