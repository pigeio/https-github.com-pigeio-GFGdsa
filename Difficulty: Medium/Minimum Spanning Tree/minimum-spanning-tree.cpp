class Solution {
  public:
    typedef pair<int,int>P;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<P , vector<P> , greater<P>>pq;
        vector<int>inMST(V , false);
        
        pq.push({0 , 0});
        int sum = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(inMST[node] == true) continue;
            inMST[node] = true;
            sum += d;
            
            for(auto &it : adj[node]){
                int neighbor = it[0];
                int neigh_dist = it[1];
                
                if(inMST[neighbor] == false){
                    pq.push({neigh_dist , neighbor});
                }
            }
        }
        return sum;
    }
};