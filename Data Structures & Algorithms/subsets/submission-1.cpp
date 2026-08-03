class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cur;

       helper(nums , 0 , cur, ans);
       return ans;
    }

    void helper(vector<int>& nums , int idx , vector<int>& cur , vector<vector<int>>& ans){
       if(idx >= nums.size()){
         ans.push_back(cur);
         return;
       }

       helper(nums,idx+1,cur,ans);
       cur.push_back(nums[idx]);
       helper(nums,idx+1,cur,ans);
       cur.pop_back();
    }
};
