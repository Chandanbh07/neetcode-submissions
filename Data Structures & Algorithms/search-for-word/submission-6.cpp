class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (dfs(board, word, visited, r, c, 0))
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board,
             string& word,
             vector<vector<bool>>& visited,
             int r,
             int c,
             int idx) {

        // All characters matched
        if (idx == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size())
            return false;

        // Wrong character or already used
        if (visited[r][c] || board[r][c] != word[idx])
            return false;

        // Choose
        visited[r][c] = true;

        // Explore 4 directions
        bool found =
            dfs(board, word, visited, r + 1, c, idx + 1) ||
            dfs(board, word, visited, r - 1, c, idx + 1) ||
            dfs(board, word, visited, r, c + 1, idx + 1) ||
            dfs(board, word, visited, r, c - 1, idx + 1);

        // Backtrack
        visited[r][c] = false;

        return found;
    }
};