/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root|| root==p || root==q)
        return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
                TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left&&right)
    return root;
    return left?left:right;
    }
};




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * };
 */  

    /*-----------------using BFS-------------------------*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> que;

        parent[root] = NULL;
        que.push(root);

        while(!que.empty()) {
            
            TreeNode* node = que.front();
            que.pop();

            if(node->left) {
                parent[node->left] = node;
                que.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                que.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;

        while(p != NULL) {
            ancestors.insert(p);
            p = parent[p];
        }

        
        while(q != NULL) {
            
            if(ancestors.find(q) != ancestors.end())
                return q;

            q = parent[q];
        }

        return NULL;
    }
};
