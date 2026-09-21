class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size(), nCols = matrix[0].size(), low = 0, high = nRows*nCols-1;
        // imagine 2D sorted matrix as 1D sorted array.
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid / nCols, col = mid % nCols;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};