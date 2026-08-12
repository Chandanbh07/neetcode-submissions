class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        for(int i = row-1; i>=0 ; i--){
            for(int j = col-1; j >=0 ; j--){
                if(board[i][j] == word[0] && helper(board,word,visited,0,i,j)) return true;
            }
        }
        return false;

    }

    bool helper(vector<vector<char>>& board, string word,vector<vector<bool>>& visited, int idx, int row, int col){       
        
        if(idx == word.size()) return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return false;
        }

        if(board[row][col] != word[idx] || visited[row][col]){
            return false;
        }

        visited[row][col] = true;

        bool found = helper(board,word,visited,idx+1,row+1,col) || helper(board,word,visited,idx+1,row-1,col) || helper(board,word,visited,idx+1,row,col-1) || helper(board,word,visited,idx+1,row,col+1);

        visited[row][col] = false;

        return found;
    }
};
