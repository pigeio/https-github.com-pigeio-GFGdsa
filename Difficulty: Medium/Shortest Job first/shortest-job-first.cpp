// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin() , bt.end());
        long long currentTime = 0, waitingTime = 0;
        for(int i = 0; i< n ;i++){
            waitingTime += currentTime;
            currentTime += bt[i];
        }
        
        return waitingTime/n;
    }
};