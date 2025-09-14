// User function Template for C++

class Solution {
  public:
    int find(int i , int par[]){
        if(i == par[i])return i;
        
        return par[i] =  find(par[i] , par);
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b, int par[], int rank1[]) {
        // code here
        int a_parent = find(a , par);
        int b_parent = find(b , par);
        
        if(a_parent == b_parent){
            return;
        }else if(rank1[a_parent] > rank1[b_parent]){
            par[b_parent] = a_parent;
        }else{
            par[a_parent] = b_parent;
            rank1++;
        }
         
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        return find(x , par) == find(y , par);
        
    }
};