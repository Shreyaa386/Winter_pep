//visit left , then right most then connect its right to parent.

//Morris Traversal is a technique to traverse a binary tree using O(1) space.
//The idea is to make use of the unused right pointers in the tree to create temporary links to the parent nodes.
//This allows us to traverse the tree without using a stack or recursion, and without modifying the tree permanently.
//The Morris Traversal algorithm can be implemented as follows:

Node Morris_traversal(Node* root){
    vector<int>ans;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr)
                prev = prev->right;

            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }           
    return ans;
}