//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj,int u , vector<bool>&visited ,int parent){
        visited[u] = true; //mark visited to the first node
      
        for(int v :adj[u]){
           if(v == parent) continue;
          
           if(visited[v]) //agar visited hai toh cycle v hoga
           return true;
           
           // agar if conditions sahi nhi hai toh aage jakr check karenge or agar aage-
           //-jakr cycle bna liya toh true return karenge
           
           if(isCycleDFS(adj,v,visited,u)){ //aage jakr agar wo cycle bna de toh 
               return true;
           }
            
        }return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v , false);
        
        for(int i=0;i<v;i++){
            
            
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends