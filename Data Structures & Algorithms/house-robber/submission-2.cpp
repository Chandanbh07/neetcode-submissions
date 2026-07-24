class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,nums.size()-1,dp);
    }

    int helper(vector<int>& nums,int n ,vector<int>& dp){
        if(n<0) return 0;
        
        if(dp[n] != -1) return dp[n];
        int notpick = 0+helper(nums,n-1,dp);
        int pick = nums[n]+helper(nums,n-2,dp);

        return dp[n] = max(notpick,pick);
    }
};
