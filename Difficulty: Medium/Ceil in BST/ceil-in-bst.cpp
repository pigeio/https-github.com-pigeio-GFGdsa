class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceilVal = -1;
        
        while(root != NULL){
            if(root->data == x){
                return root->data;
            }
            if(root->data > x){
                ceilVal = root->data;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        
        return ceilVal;
    }
};
