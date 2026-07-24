class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2 != 0) return false;
        return helper(nums,0,sum/2);
    }

    bool helper(vector<int>& nums,int idx,int target){
        int n = nums.size();
        if(target == 0) return true;

        if(idx == n){
            return false;
        }
        
        bool notpick = helper(nums,idx+1,target);
        bool pick = false;
        if(nums[idx] <= target) pick = helper(nums,idx+1,target-nums[idx]);

        return pick || notpick;

    }
};
