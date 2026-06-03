class Solution {
   public:
    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') return;

        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';

                else if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};