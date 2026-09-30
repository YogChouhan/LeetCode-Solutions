/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        vector<int> postOrder;
        stack<TreeNode*> st;
        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = st.top()->right;
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return postOrder;
    }
};

// TC: O(2N), SC: O(2N)

// class Solution {
// public:
//     vector<int> result;
//     void postOrder(TreeNode *root){
//         if(root == nullptr) return;
//         postOrder(root->left);
//         postOrder(root->right);
//         result.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         postOrder(root);
//         return result;
//     }
// };