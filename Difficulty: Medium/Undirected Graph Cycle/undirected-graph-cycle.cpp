//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleBFS(vector<vector<int>>& adj,int u , vector<bool>&visited){
       queue<pair<int, int>>que;
       
       que.push({u,  -1});
       visited[u] = true; // that means it is visited
       
       while(!que.empty()){
           pair<int , int> p = que.front();
           que.pop();
           
           int source = p.first;
           int parent = p.second;
           
           for(int &v : adj[source]){
               if(visited[v] == false){ //agar visited nhi hai toh visit karenge
                   visited[v] = true;
                   que.push({v , source});
               }else if(v != parent){ // agar wo parent ke equal nhi hai toh wo cycle hoi
                   return true;
               }else{
                   
               }
           }
       }return false;
       
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v , false);
        
        for(int i=0;i<v;i++){
            
            
            if(!visited[i] && isCycleBFS(adj,i,visited)){
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