class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2 != 0) return false;
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2 +1 , -1));
        return helper(nums,0,sum/2,dp);
    }

    bool helper(vector<int>& nums,int idx,int target , vector<vector<int>> dp){
        int n = nums.size();
        
        if(target == 0) return true;

        if(idx == n){
            return false;
        }

        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool notpick = helper(nums,idx+1,target,dp);
        bool pick = false;
        if(nums[idx] <= target) pick = helper(nums,idx+1,target-nums[idx],dp);

        return dp[idx][target] = pick || notpick;
    }
};
