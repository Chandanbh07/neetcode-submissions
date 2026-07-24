class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer , Integer> map = new HashMap<>();

        for(int i = 0; i < nums.length ; i++){
            int needed = target - nums[i];

            if(map.containsKey(needed)){
                int j = map.get(needed);
                return new int[]{j,i};
            }
            map.put(nums[i],i);
        }
        return new int[]{-1,-1};
    }
}
