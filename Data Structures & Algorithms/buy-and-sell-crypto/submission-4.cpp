class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int buy = prices[0];

        for(int i = 0 ; i < prices.size() ; i++){
            if(buy > prices[i]) buy = prices[i];

            maxi = max(maxi , prices[i] - buy);
        }
        return maxi;
    }
};
