class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        int ans = helper(coins,n-1,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int helper(vector<int>& coins , int idx , int target ,vector<vector<int>>& dp){

        for(int i=0;i<=idx;i++){
            dp[i][0] = 0;
        }
        for(int tar = 1;tar<=target;tar++){
            dp[0][tar] = (tar % coins[0] == 0)? tar/coins[0] : 1e9;
        }
        
        for(int i = 1;i <= idx;i++){
            for(int tar = 1;tar<=target;tar++){
                int notpick = dp[i-1][tar];
                int pick = 1e9;
                if(tar >= coins[i]){
                   pick = 1+dp[i][tar-coins[i]];
                }
                dp[i][tar] = min(pick,notpick);
            }
        }

        return dp[idx][target];
    }
};
