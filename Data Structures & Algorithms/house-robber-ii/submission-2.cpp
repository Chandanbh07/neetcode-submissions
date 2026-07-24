class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n-1,-1);
        vector<int> temp1(nums.begin()+1,nums.end());

        vector<int> dp2(n-1,-1);
        vector<int> temp2(nums.begin(),nums.end()-1);

        return max(helper(temp1,n-2,dp1),helper(temp2,n-2,dp2));
    }

    int helper(vector<int>& nums,int n,vector<int>& dp){
        if(n<0) return 0;
        
        if(dp[n] != -1) return dp[n];
        int notpick = helper(nums,n-1,dp);
        int pick = nums[n]+helper(nums,n-2,dp);

        return dp[n]=max(notpick,pick);
    }
};
