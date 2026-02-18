/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   int solve(Node* root, int level){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL && level%2==1)
        return level;
        int left=solve(root->left,level+1);
        int right=solve(root->right,level+1);
        return max(left,right);
        }
    int depthOfOddLeaf(Node *root) {
        // code here
       return solve(root,1);
    }
};