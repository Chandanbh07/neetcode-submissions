class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;

        for(int a:nums){
            s.insert(a);
        }

        if(s.size() == nums.size()) return false;
        return true;
    }
};