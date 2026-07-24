class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            int required = target - nums[i];
            for(int j = i+1 ; j < n ; j++){
                if(required == nums[j]){
                    return {i,j};
                }
            }
        }
    }
};
