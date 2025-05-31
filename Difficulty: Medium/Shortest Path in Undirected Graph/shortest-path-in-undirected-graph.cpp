class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int n = adj.size();
        vector<int>result(n , INT_MAX);
        
        result[src] = 0;
        pq.push({0 , src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &neighbor : adj[node]){
                
                if(d+1 < result[neighbor]){
                    result[neighbor] = d+1;
                    pq.push({d+1 , neighbor});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(result[i] == INT_MAX) {
                result[i] = -1;
            }
        }
        return result;
    }
};