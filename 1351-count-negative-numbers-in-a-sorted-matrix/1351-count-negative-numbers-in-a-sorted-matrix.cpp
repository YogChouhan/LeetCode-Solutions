class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(grid[i][0] < 0) {
                cnt += m;
                continue;
            }
            for(int j = 1; j < m; j++){
                if(grid[i][j] < 0){
                    cnt += m-j;
                    break;
                }
            }
        }

        return cnt;
    }
};