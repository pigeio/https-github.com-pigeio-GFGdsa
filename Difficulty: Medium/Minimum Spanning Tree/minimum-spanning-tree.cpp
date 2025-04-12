//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int,int> p;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<p , vector<p>,greater<p>> pq;
        vector<int>visited(V,false);
        
        int sum = 0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(visited[node] == true){
                continue;
            }
            
            visited[node] = true; // agar visited nhi hai toh visit kro
            sum += wt;
            
            for(auto &neighbor :adj[node]){ //or uss node se dekhenge ke wo kaha kaha jata hai
                int adjNode = neighbor[0];
                int edge_wt = neighbor[1];
                
                if(!visited[adjNode]){  //agar neighbor already visited nh hai toh usko pq me daal denge 
                    pq.push({edge_wt , adjNode});
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends