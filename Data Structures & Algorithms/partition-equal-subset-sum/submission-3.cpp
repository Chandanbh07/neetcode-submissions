class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2 != 0) return false;
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2 +1 , 0));
        return helper(nums,0,sum/2,dp);
    }

    bool helper(vector<int>& nums,int idx,int target , vector<vector<int>>& dp){
        int n = nums.size();

        for(int i=1;i<n;i++) dp[i][0] = true;
        if(nums[0]<=target) dp[0][nums[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int tar = 1;tar<=target;tar++){
                bool notpick = dp[i-1][tar];
                bool pick = false;
                if(nums[i] <= tar) pick = dp[i-1][tar-nums[i]];

                dp[i][tar] = pick || notpick;
            }
        }

        return dp[n-1][target];
    }
};
