class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n-1;

        return bs(nums,st,end,target);
    }

    int bs(vector<int>& nums, int st, int end, int target){
        if(st>end) return -1;
        
        int mid = st + (end - st) /2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            return bs(nums,mid+1,end,target);
        }else{
            return bs(nums,st,mid-1,target);
        }
    }
};
