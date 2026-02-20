
/*-------------------------------------------Recursive Approach------------------------------------------------*/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val<low)
        return rangeSumBST(root->right,low,high);
        if(root->val>high)
        return rangeSumBST(root->left,low,high);
        return root->val
                +rangeSumBST(root->left,low,high)
                +rangeSumBST(root->right,low,high);
    }
};




/*--------------------------Iterative Approach using BFS (queue)---------------------------*/


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
    int rangeSumBST(TreeNode* root, int low, int high) {
      if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(!node) continue;
            
            if(node->val >= low && node->val <= high)
                sum += node->val;
            
            if(node->val > low)
                q.push(node->left);
            
            if(node->val < high)
                q.push(node->right);
        }
        
        return sum;
    }
};




/*-------------------------------Iterative Approach using DFS (stack)------------------------------------*/


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
    int rangeSumBST(TreeNode* root, int low, int high) {
  stack<TreeNode*> st;
        TreeNode* curr = root;
        int sum = 0;
        
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            if(curr->val >= low && curr->val <= high)
                sum += curr->val;
            
            if(curr->val > high)
                break;
            
            curr = curr->right;
        }
        
        return sum;
    }
};