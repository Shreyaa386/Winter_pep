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

     int diameter=0;
        int height(TreeNode* root){
            if(root==NULL) return 0;
            int left = height(root->left);
            int right= height(root->right);
            diameter=max(diameter, left+right);
            return 1+max(left,right);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        
       height(root);
       return diameter;

    }
};



  /*-------------------using BFS----------------------*/
class Solution {
public:

        int height(TreeNode* root){
            if(root==NULL) return 0;
            return 1+max(height(root->left), height(root->right));
        }
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL) return 0;
       int diameter=0;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        int leftH = height(front->left);
        int rightH = height(front->right);
        diameter= max(diameter,leftH+rightH);
        if(front->left) q.push(front->left);
        if(front->right)q.push(front->right);
       } 
       return diameter;
    }
};