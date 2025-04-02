//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool checkBipartiteDFS(vector<vector<int>>& adj , int curr , vector<int> &color , int currcolor){
        color[curr] = currcolor;  // current node me current color bhar denge
        
        for(int &v : adj[curr]){
            if(color[v] == color[curr]){  // b-->a ka same color hsi toh false hoga
                return false;
            }
            if(color[v] == -1){  // never colored
                color[v] = 1-color[curr];
            
                if(checkBipartiteDFS(adj , v, color , color[v]) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int>color(v,-1);  //start me koi colored nhi hai
        
        //red = 1
        //green = 0
        
        for(int i = 0; i<v ; i++){
            if(color[i] == -1){
                if(checkBipartiteDFS(adj , i , color , 1) == false){
                    return false;
                }
            }
            return true; 
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends