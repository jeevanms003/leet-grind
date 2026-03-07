class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;   // mark visited

        int area = 1;

        area += dfs(r+1, c, grid);
        area += dfs(r-1, c, grid);
        area += dfs(r, c+1, grid);
        area += dfs(r, c-1, grid);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }

            }
        }

        return maxArea;
    }
};