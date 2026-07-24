class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // dp[idx][prevIdx+1]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev = idx-1; prev >= -1; prev--) {

                // not pick
                int notPick = dp[idx+1][prev+1];

                // pick
                int pick = 0;
                if(prev == -1 || nums[idx] > nums[prev]) {
                    pick = 1 + dp[idx+1][idx+1];
                }

                dp[idx][prev+1] = max(pick, notPick);
            }
        }

        return dp[0][0]; // prev = -1 → index 0
    }
};


    // int helper(vector<int>& nums , int idx , int prev , vector<vector<int>>& dp){
    
    //     int n = nums.size();
    //     if(idx == n) return 0;

    //     if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    //     int notpick = 0+helper(nums,idx+1,prev,dp);
    //     int pick = 0;
    //     if(prev == -1 || nums[prev] < nums[idx]) pick = 1+helper(nums,idx+1,idx,dp);

    //     return dp[idx][prev+1] = max(notpick,pick);
    // }

