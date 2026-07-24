class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int tar=1;tar<=amount;tar++){
            if(tar % coins[0] == 0){
                dp[0][tar] = 1;
            }
        }
        
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=amount;target++){
                
                int notpick = dp[idx-1][target];
                int pick = 0;
                if(coins[idx] <= target){
                   pick = dp[idx][target-coins[idx]];
                }
                dp[idx][target] = pick+notpick;
            }
        }

        return dp[n-1][amount];
    }

    // int helper(vector<int>& coins,int idx,int target , vector<vector<int>>& dp){
    //     if(target == 0) return 1;

    //     if(idx == 0){
    //         if(target % coins[0] == 0) return 1;
    //         else return 0;
    //     }

    //     if(dp[idx][target] != -1) return dp[idx][target];
    //     int notpick = helper(coins,idx-1,target,dp);
    //     int pick = 0;
    //     if(coins[idx] <= target){
    //         pick = helper(coins,idx,target-coins[idx],dp);
    //     }
    //     return dp[idx][target] = pick+notpick;
    // }
};
