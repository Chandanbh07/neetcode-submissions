class Solution {
public:
    vector<vector<string>> ans;
    bool is_valid(vector<string>& grid,int row, int col){
        int n = grid.size();

        for(int i=0; i<grid.size(); i++){
            if(grid[row][i] == 'Q') return false;
        }

        for(int i=0; i<grid.size(); i++){
            if(grid[i][col] == 'Q') return false;
        }

        for(int i=row, j=col; i<n && j<n ; i++,j++ ){
            if(grid[i][j] == 'Q') return false;
        }

        for(int i=row,j=col ; i<n && j>=0; i++,j--){
            if(grid[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<string>& grid,int n){
        if(n == 0){
            ans.push_back({grid});
            return;
        }

        for(int i=0; i<grid.size(); i++){
            if(is_valid(grid, n-1,i)){
                grid[n-1][i] = 'Q';
                helper(grid,n-1);
                grid[n-1][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n,'.'));
        
        helper(grid,n);
        return ans;
    }
};
