class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(nums,0,-1,dp);
    }

    int helper(vector<int>& nums , int idx , int prev , vector<vector<int>>& dp){
        int n = nums.size();
        if(idx == n) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int notpick = 0+helper(nums,idx+1,prev,dp);
        int pick = 0;
        if(prev == -1 || nums[prev] < nums[idx]) pick = 1+helper(nums,idx+1,idx,dp);

        return dp[idx][prev+1] = max(notpick,pick);
    }
};
