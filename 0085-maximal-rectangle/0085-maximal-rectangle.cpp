class Solution {
private:
    //maximum area problem 84 code
    int largestHistogram(vector<int>& heights) {
        int n = heights.size(), maxArea = 0, nse, pse, element;
        stack<int> st; //stores the indexes

        // we are basically finding the nse and pse for elements along with the traversal
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){ 
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element]*(nse - pse - 1)); //formula to find the area
            }
            st.push(i);
        }

        while(!st.empty()){
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element]*(nse - pse - 1));
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size(), maxArea = 0;
        vector<int> heights(m, 0);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(matrix[row][col] == '1') heights[col]++;
                else heights[col] = 0;
            }
            maxArea = max(maxArea, largestHistogram(heights));
        }
        
        return maxArea;
    }
};