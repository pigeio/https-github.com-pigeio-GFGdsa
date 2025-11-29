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
    int floor(Node* root, int x) {
        // code here
        int floorVal = -1;
        
        while(root != NULL){
            if(root->data == x){
                return root->data;
            }
            if(root->data < x){
                floorVal = root->data;
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return floorVal;
    }
};