// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int>result(100000, 1e9);
        
        pq.push({0 , start});
        result[start] = 0;
        int mod = 100000;
        
        while(!pq.empty()){
            int steps = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(node == end) return steps;
            
            for(auto &it : arr){
                int num = (1LL*it*node) % mod;
                
                if(steps+1 < result[num]){
                    result[num] = steps+1;
                    pq.push({steps+1 , num});
                }
            }
            
        }
        return -1;
    }
};
