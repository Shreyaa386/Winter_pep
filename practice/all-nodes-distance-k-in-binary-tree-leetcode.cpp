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

     void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }

            if(node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> mp;
        
        // build parent map
        markParents(root, mp);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while(!q.empty()) {

            int size = q.size();

            if(dist == k)
                break;

            dist++;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

               
                if(node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

               
                if(mp.find(node) != mp.end() && visited.find(mp[node]) == visited.end()) {
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
        }

        vector<int> result;

        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
        }
    
};