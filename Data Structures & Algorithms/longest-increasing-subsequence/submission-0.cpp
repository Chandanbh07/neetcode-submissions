class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,INT_MIN);
    }

    int helper(vector<int>& nums , int idx , int last){
        int n = nums.size();
        if(idx == n) return 0;

        int notpick = 0+helper(nums,idx+1,last);
        int pick = 0;
        if(last < nums[idx]) pick = 1+helper(nums,idx+1,nums[idx]);

        return max(notpick,pick);
    }
};
