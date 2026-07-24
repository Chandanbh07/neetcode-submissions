class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int idx = n-1;idx>=0;idx--){
            for(int buy=0;buy <= 1;buy++){
                if(buy){
                    dp[idx][buy] = max(-prices[idx]+dp[idx+1][0] , dp[idx+1][1]);
                }else{
                    dp[idx][buy] = max(prices[idx]+dp[idx+2][1] , dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }

    // int helper(vector<int>& prices,int idx,int buy){
    //     if(idx >= prices.size()) return 0;

    //     if(buy){
    //         return max(-prices[idx] + helper(prices,idx+1,0) , 0 + helper(prices,idx+1,1)); 
    //     }else{
    //         return max(prices[idx] + helper(prices,idx+2,1) , 0 + helper(prices,idx+1,0));
    //     }
    // }
};
