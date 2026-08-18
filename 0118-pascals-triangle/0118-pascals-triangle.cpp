class Solution {
private:
    vector<int> generateRow(int row){
        long long term=1;
        vector<int> ans;
        ans.push_back(1);
        for(int col=1; col<row; col++){
            term=term*(row-col);
            term=term/col;
            ans.push_back(term);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ansList;
        for(int i=1; i<=numRows; i++){
            ansList.push_back(generateRow(i));
        }
        return ansList;
    }
};