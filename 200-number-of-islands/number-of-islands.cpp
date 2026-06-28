class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary and water check
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;

        // mark visited
        grid[r][c] = '0';

        // explore 4 directions
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {
                    islands++;          // new island found
                    dfs(i, j, grid);    // mark entire island
                }

            }
        }

        return islands;
    }
};


