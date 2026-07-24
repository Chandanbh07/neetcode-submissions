class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> map;

        for(int i = 0 ; i < n ;i++){
            int needed = target - nums[i];
            if(map.find(needed) != map.end()){
                return {map[needed],i};
            }
            map[nums[i]] = i;
        }
    }
};
