class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;

            if (visited[nr][nc])
                continue;

            // Reverse flow condition
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, nr, nc, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific (top row + left column)
        for (int c = 0; c < cols; c++)
            dfs(heights, 0, c, pacific);

        for (int r = 0; r < rows; r++)
            dfs(heights, r, 0, pacific);

        // Atlantic (bottom row + right column)
        for (int c = 0; c < cols; c++)
            dfs(heights, rows - 1, c, atlantic);

        for (int r = 0; r < rows; r++)
            dfs(heights, r, cols - 1, atlantic);

        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c])
                    ans.push_back({r, c});
            }
        }

        return ans;
    }
};