class Solution {
private:
    int findMaxRowIndex(vector<vector<int>>& mat, int n, int m, int mid){
        int maxi = -1, maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int maxRowIndex = findMaxRowIndex( mat, n, m, mid);
            int left = mid-1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid+1 < m ? mat[maxRowIndex][mid+1] : -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) return {maxRowIndex, mid};
            else if(mat[maxRowIndex][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};