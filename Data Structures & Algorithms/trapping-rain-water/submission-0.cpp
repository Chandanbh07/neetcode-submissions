class Solution {
public:
    int trap(vector<int>& height) {
        int maxi=0;
        int n = height.size();
        vector<int> left(n,0),right(n,0);

        for(int i=0;i<n;i++){
            maxi = max(height[i],maxi);
            left[i] = maxi;
        }

        maxi = 0;

        for(int i=n-1;i>=0;i--){
            maxi = max(height[i],maxi);
            right[i] = maxi;
        }
        
        int trap=0;
        for(int i=0;i<n;i++){
            trap += min(left[i],right[i])-height[i];
        }
        return trap;
    }
};
