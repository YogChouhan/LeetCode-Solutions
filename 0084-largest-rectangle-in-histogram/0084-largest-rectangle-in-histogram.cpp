class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};