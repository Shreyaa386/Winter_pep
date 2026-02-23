/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    
   
    int countNodes(Node* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isCBT(Node* root, int index, int total) {
        if(!root) return true;
        
        if(index >= total)
            return false;
        
        return isCBT(root->left, 2*index + 1, total) &&
               isCBT(root->right, 2*index + 2, total);
    }
    
    bool isMaxHeap(Node* root) {
        if(!root) return true;
        
        if(root->left) {
            if(root->data < root->left->data)
                return false;
        }
        
        if(root->right) {
            if(root->data < root->right->data)
                return false;
        }
        
        return isMaxHeap(root->left) &&
               isMaxHeap(root->right);
    }
    
    bool isHeap(Node* tree) {
        // code here
         int total = countNodes(tree);
        
        if(!isCBT(tree, 0, total))
            return false;
            
        return isMaxHeap(tree);
    }
};