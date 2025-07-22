class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        int sum = 0;
        priority_queue<int , vector<int> , greater<int>>pq;
        
        for(auto &i : arr){
            pq.push(i);
        }
            
            while(pq.size() > 1){
                int first = pq.top(); pq.pop();
                int second = pq.top(); pq.pop();
                int combined = first + second;
                sum += combined;
                pq.push(combined);
            }
            
        
        return sum;
        
    }
};