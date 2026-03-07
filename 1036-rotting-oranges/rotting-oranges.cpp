class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;

        // initial scan
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        while(!q.empty() && fresh > 0) {

            int size = q.size();
            minutes++;

            for(int i = 0; i < size; i++) {

                auto [r,c] = q.front();
                q.pop();

                if(r+1 < m && grid[r+1][c] == 1) {
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                    fresh--;
                }

                if(r-1 >= 0 && grid[r-1][c] == 1) {
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                    fresh--;
                }

                if(c+1 < n && grid[r][c+1] == 1) {
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                    fresh--;
                }

                if(c-1 >= 0 && grid[r][c-1] == 1) {
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                    fresh--;
                }
            }
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};