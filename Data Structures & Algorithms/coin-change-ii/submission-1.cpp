class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(coins,n-1,amount,dp);
    }

    int helper(vector<int>& coins,int idx,int target , vector<vector<int>>& dp){
        if(target == 0) return 1;

        if(idx == 0){
            if(target % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];
        int notpick = helper(coins,idx-1,target,dp);
        int pick = 0;
        if(coins[idx] <= target){
            pick = helper(coins,idx,target-coins[idx],dp);
        }
        return dp[idx][target] = pick+notpick;
    }
};
