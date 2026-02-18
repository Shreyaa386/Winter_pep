/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root==NULL)
        return -1;
        return 1+max(height(root->left),height(root->right));
    }
};


     /*------------using BFS-----------------*/
class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root==NULL) return -1;
        queue<Node*>q;
        q.push(root);
        int h = 0;
        while(!q.empty()){
            int n=q.size();
          //  h++;
            for(int i=0;i<n;i++){
                Node* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            h++;
        }
        return h-1;
    }
};