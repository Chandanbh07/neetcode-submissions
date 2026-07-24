class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return helper(prices,0,1);
    }

    int helper(vector<int>& prices,int idx,int buy){
        if(idx >= prices.size()) return 0;

        if(buy){
            return max(-prices[idx] + helper(prices,idx+1,0) , 0 + helper(prices,idx+1,1)); 
        }else{
            return max(prices[idx] + helper(prices,idx+2,1) , 0 + helper(prices,idx+1,0));
        }
    }
};
