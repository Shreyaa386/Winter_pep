/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root==NULL) return "";
       queue<TreeNode*>q;
       q.push(root);
       string result="";
       while(!q.empty()){
        TreeNode* front =q.front();
        q.pop();
        if(front){
            result+=to_string(front->val)+",";
            q.push(front->left);
            q.push(front->right);
        }else{
            result+="null,";
        }
       } 
       return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        string item;
        getline(ss,item,',');
        TreeNode* root=new TreeNode(stoi(item));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            getline(ss,item,',');
            if(item!="null"){
                front->left= new TreeNode(stoi(item));
                q.push(front->left);
            }
            getline(ss,item,',');
            if(item!="null"){
                front->right = new TreeNode(stoi(item));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));