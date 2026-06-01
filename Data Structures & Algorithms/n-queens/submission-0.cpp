class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    bool isSafe(int row, int col, int n,
                vector<int>& leftRow,
                vector<int>& upperDiag,
                vector<int>& lowerDiag) {
        if (leftRow[row] || lowerDiag[row + col] || upperDiag[n - 1 + col - row])
            return false;
        return true;
    }

    void solve(int col, int n,
               vector<int>& leftRow,
               vector<int>& upperDiag,
               vector<int>& lowerDiag) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, leftRow, upperDiag, lowerDiag)) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, n, leftRow, upperDiag, lowerDiag);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        solve(0, n, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};