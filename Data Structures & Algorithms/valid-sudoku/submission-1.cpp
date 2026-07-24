class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9) , col(9) , box(9);

        for(int i=0;i<9 ; i++){
            for(int j=0;j<9;j++){
                char num = board[i][j];

                if(num == '.') continue;

                int box_idx = (i/3) * 3 + (j/3);

                if(row[i].count(num) || col[j].count(num) || box[box_idx].count(num)) return false;

                row[i].insert(num);
                col[j].insert(num);
                box[box_idx].insert(num);

            }
        }
        return true;
    }
};
