/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q; // (node , horizontal distance)
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty()){
            Node* curr = q.front().first;
            int currHD = q.front().second;
            q.pop();
            
            mp[currHD] = curr->data;

            if(curr->left != NULL){
                q.push({curr->left , currHD-1});
            }
            if(curr->right != NULL){
                q.push({curr->right , currHD+1});
            }
        }
        
        vector<int>ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};