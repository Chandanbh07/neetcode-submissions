class Solution {
public:
    int helper(vector<int>& cost, int i) {
        int n = cost.size();
        if (i >= n) return 0; // reached or passed top
        
        int oneStep = cost[i] + helper(cost, i + 1);
        int twoStep = cost[i] + helper(cost, i + 2);
        
        return min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost, 0), helper(cost, 1));
    }
};
