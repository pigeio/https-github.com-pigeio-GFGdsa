//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleDFS(vector<vector<int>> &adj , int u , vector<bool> &visited , vector<bool> &inRecursion){
        visited[u] = true; //jispe aaye ho usko true mark karo
        inRecursion[u] = true;
        
        for(int &V : adj[u]){
            if(visited[V] != true && isCycleDFS(adj , V , visited , inRecursion)){
                return true;
            }else if(inRecursion[V] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i = 0 ; i<V ; i++){
            if(!visited[i] && isCycleDFS(adj , i , visited , inRecursion)){ //agar visited nhi hai-
            //toh isCycleDfs ko call karenge or check karenge cycle hai ya nhi
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends