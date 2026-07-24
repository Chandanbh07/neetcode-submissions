class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        helper(board , 0 , n);
        return ans;
    }

    void helper(vector<string>& board, int row , int n){
        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int col=0;col<board[0].size();col++){
            if(issafe(board,row,col,n)){
                board[row][col] = 'Q';
                helper(board,row+1,n);
                board[row][col] = '.';
            }
        }
    }

    bool issafe(vector<string>& board, int row , int col , int n){

        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q') return false;
        }

        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        for(int i=row , j=col ; i>=0 && j<n ; i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
};
