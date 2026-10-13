class Solution {
private:
    bool dfs(int node, int currentColor, vector<int>& color, vector<vector<int>>& graph){
        color[node] = currentColor;
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(dfs(it, !currentColor, color, graph) == false) return false;
            }
            else if(color[it] == currentColor){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int noOfNodes = graph.size();
        vector<int> color(noOfNodes, -1);
        
        for(int i = 0; i < noOfNodes; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};

// TC: O(Vertices + Edges)
// SC: O(Vertices)