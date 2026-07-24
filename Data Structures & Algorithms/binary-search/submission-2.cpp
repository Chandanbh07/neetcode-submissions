class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return binsearch(nums,target,0,n-1);
    }

    int binsearch(vector<int>& nums , int target , int st , int end){
        if(st>end) return -1;
        int mid = st + (end-st) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return binsearch(nums,target,mid+1,end);
        else{
            return binsearch(nums,target,st,mid-1);
        }
    }
};
