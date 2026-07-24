class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n-1,0);
        vector<int> temp1(nums.begin()+1,nums.end());

        vector<int> dp2(n-1,0);
        vector<int> temp2(nums.begin(),nums.end()-1);

        return max(helper(temp1,temp1.size(),dp1),helper(temp2,temp2.size(),dp2));
    }

    int helper(vector<int>& nums,int n,vector<int>& dp){
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int notpick = prev1;
            int pick = nums[i]+prev2;

            prev2 = prev1;
            prev1=max(notpick,pick);
        }
        return prev1;
    }
};
