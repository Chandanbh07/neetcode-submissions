class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int bestbuy=prices[0];
        int prop = 0;

        for(int i=1;i<n;i++){
            bestbuy = min(bestbuy , prices[i]);
            prop = max(prop , prices[i]-bestbuy);
        }
        return prop;
    }
};
