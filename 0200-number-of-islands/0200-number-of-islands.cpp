class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size(), m = grid[0].size();

        int nRowFormula[] = {-1, 0, +1, 0};
        int nColFormula[] = {0, +1, 0, -1};

        while(!q.empty()){ // till the queue is not empty
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // traverse in the neighbour and mark the land (other elements which are 1)
            for(int i = 0; i < 4; i++){
                int nrow = r + nRowFormula[i];
                int ncol = c + nColFormula[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol]=='1' && visited[nrow][ncol]==0){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m , 0));

        int numberOfIslands = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(visited[row][col] == 0 && grid[row][col] == '1'){
                    numberOfIslands++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return numberOfIslands;
    }
};

// TC: O(N * M)
// SC: O(N * M)