//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    vector<int>parent;
    vector<int>rank;
    
    int find(int x ){ // path compressed code
        if(x == parent[x])
        return x;
        
        return parent[x] = find(parent[x]); 
    }
    
    void unionSets(int x , int y){ //rank optimized code
        int x_parent = find(x);
        int y_parent = find(y);
    
        if(x_parent == y_parent)
        return;
    
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            
            rank[y_parent] += 1;
        }
    }    
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    
	    parent.resize(V);
	    rank.resize(V , 0);
	    
	    for(int i = 0; i < V; i++) {
            parent[i] = i;
        }
	    
	    for(int u=0;u<V;u++){
	        for(int &v :adj[u]){
	            if(u<v){
	                int parent_u = find(u);
	                int parent_v = find(v);
	                
	                if(parent_u == parent_v)
	                return true;
	                
	                unionSets(u , v);
	            }
	        }
	    }
	    return false;
	    
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends