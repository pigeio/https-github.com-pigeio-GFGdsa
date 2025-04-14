//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void DFS(vector<int> adj[], int u, vector<bool>& visited) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }

    bool isConnected(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        // Find a vertex with non-zero degree to start DFS
        int start = -1;
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        // If no edges in the graph
        if (start == -1)
            return true;

        // Start DFS from a vertex with non-zero degree
        DFS(adj, start, visited);

        // Check if all vertices with non-zero degree are visited
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty() && !visited[i]) {
                return false;
            }
        }
        return true;
    }

    int isEulerCircuit(int V, vector<int> adj[]) {
        if (!isConnected(V, adj))
            return 0;

        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                odd++;
        }

        if (odd > 2)
            return 0;  // No Euler path or circuit
        else if (odd == 2)
            return 1;  // Euler Path
        else
            return 2;  // Euler Circuit
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends