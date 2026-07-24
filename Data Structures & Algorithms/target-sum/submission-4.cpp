class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num:nums) sum+=num;
        if(abs(target) > sum) return 0;
        
        if((sum+target)%2 != 0) return 0;
        int tar = (sum+target)/2;
        return helper(nums,tar,n-1);
    }

    int helper(vector<int>& nums,int target,int idx){
        
        if(idx < 0){
            if(target == 0) return 1;
            return 0;
        }
        
        int notpick = helper(nums,target,idx-1);
        int pick = 0;
        if(nums[idx] <= target) pick = helper(nums,target-nums[idx],idx-1);

        return pick+notpick;
    }
};
