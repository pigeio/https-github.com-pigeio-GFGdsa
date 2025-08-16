struct job{
    int deadline;
    int profit;
};

bool myC(job a , job b){
    return a.profit > b.profit;
}

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<job>jobs;
        for(int i = 0; i< n; i++){
            jobs.push_back({deadline[i] , profit[i]});
        }
        
        sort(jobs.begin() , jobs.end() , myC);
        
        int maxDeadline = 0;
        for(int i = 0; i<n ;i++){
            maxDeadline = max(maxDeadline , jobs[i].deadline);
        }
        
        vector<int>slot(maxDeadline+1 , -1);
        
        int totalJob = 0 ,totalProfit = 0;
        for(int i = 0; i< n;i++){
            for(int j = jobs[i].deadline ; j >0 ; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    totalJob++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }
        return {totalJob , totalProfit};
    }
};