class Solution {
  public:
    int n;
    int solve(vector<int> &arr , int s , int e ,vector<vector<int>>& dp){
        if(s == e)return 0;
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        
        int mini = 1e9;
        for(int k = s; k < e; k++){
            int step = arr[s-1]*arr[k]*arr[e] + solve(arr,s,k ,dp) + solve(arr,k+1,e,dp);
            mini = min(mini ,step);
        }
        return dp[s][e] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        n = arr.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        return solve(arr , 1 , n-1 , dp);
    }
};