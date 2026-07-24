class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        sort(nums.begin(),nums.end());
        int maxcount=1,curcount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) continue;
            
            if(nums[i] == nums[i-1]+1) curcount++;
            else{
                curcount = 1;
            }
            maxcount = max(maxcount,curcount);
        }
        return maxcount;
    }
};
