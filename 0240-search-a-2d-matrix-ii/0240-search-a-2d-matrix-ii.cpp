class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // n = number of rows
        // m = number of cols
        // we start the traversal from TOP RIGHT corner of matrix
        int n = matrix.size(), m = matrix[0].size(), row = 0, col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // n = number of rows
//         // m = number of cols
//         // we start the traversal from BOTTOM LEFT corner of matrix
//         int n = matrix.size(), m = matrix[0].size(), row = n-1, col = 0;
//         while(row >= 0 && col < m){
//             if(matrix[row][col] == target){
//                 return true;
//             }
//             else if(matrix[row][col] < target) col++;
//             else row--;
//         }
//         return false;
//     }
// };