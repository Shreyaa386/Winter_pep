/*
Structure of the node of the binary tree is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
class Solution {
  public:
  
         int solve(Node* node, int target, int level){
        
        if(node == NULL)
            return 0;
        
        if(node->data == target)
            return level;
        
        int left = solve(node->left, target, level+1);
        
        if(left != 0)
            return left;
        
        return solve(node->right, target, level+1);
    }
    // function should return level of the target node
    int getLevel(struct Node *node, int target) {
        // code here
         return solve(node, target, 1);
        
    }
};