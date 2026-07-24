class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(0,0,m,n);
    }

    int helper(int i,int j, int m ,int n){
        if(i == m-1 && j == n-1) return 1;

        if(i >= m || j>=n) return 0;

        int right = helper(i,j+1,m,n);
        int down = helper(i+1,j,m,n);

        return right+down;
    }
};
