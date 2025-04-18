//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int V = adj.size();
        vector<int>result(V , INT_MAX);
        
        result[src] = 0; //source se source ka disatnce by default 0 he hoga
        pq.push({0 , src});
        
        while(!pq.empty()){  // all about min_heap
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &vec : adj[node]){ // all about adjacent node 
                int adjNode = vec.first;
                int dist    = vec.second;
                
                if(d+dist < result[adjNode]){
                    result[adjNode] = d+dist;
                    pq.push({d+dist , adjNode});
                }
            }
        }
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends