class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = helper(coins,n-1,amount);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int helper(vector<int>& coins , int idx , int target){
        if(target == 0) return 0;

        if(idx == 0){
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }
        
        int notpick = helper(coins,idx-1,target);
        int pick = 1e9;
        if(target >= coins[idx]){
            pick = 1+helper(coins,idx,target-coins[idx]);
        }

        return min(pick,notpick);
    }
};
