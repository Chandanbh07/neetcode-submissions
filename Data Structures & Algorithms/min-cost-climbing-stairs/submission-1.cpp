class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost , cost.size()-1 ) , helper(cost , cost.size()-2));
    }

    int helper(vector<int>& cost , int n){
        if(n <= 1) return cost[n];

        return cost[n]+min(helper(cost,n-1) , helper(cost,n-2));
    }
};
