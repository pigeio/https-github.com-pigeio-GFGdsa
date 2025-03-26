//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool BFS(vector<vector<int>> &adj , int u,vector<bool> &visited , vector<int> &result){
      queue<int>que;
      
      que.push(u);
      visited[u] = true;
      result.push_back(u);
      
      while(!que.empty()){
          int u = que.front();
          que.pop();
          
          for(int &v : adj[u]){
              if(!visited[v]){
                  que.push(v);
                  visited[v] = true;
                  result.push_back(v);
              }
          }
      }
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int>result;
        int v = adj.size();
        vector<bool>visited(v, false);
        
        BFS(adj , 0 , visited,result);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends