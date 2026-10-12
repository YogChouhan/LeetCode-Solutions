class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& answer, vector<vector<int>>& image, int newColor, int rowFormula[], int colFormula[], int initialColor){
        answer[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            int nRow = row + rowFormula[i];
            int nCol = col + colFormula[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && answer[nRow][nCol] != newColor && image[nRow][nCol] == initialColor){
                dfs(nRow, nCol, answer, image, newColor, rowFormula, colFormula, initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> answer = image;

        int rowFormula[] = {-1, 0, +1, 0};
        int colFormula[] = {0, +1, 0, -1};

        dfs(sr, sc, answer, image, color, rowFormula, colFormula, initialColor);

        return answer;
    }
};