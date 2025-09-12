class Solution {
  public:
    
    bool solve(vector<int>& arr,int idx , int sum, vector<vector<int>>& dp){
        if(sum == 0)return true;
        
        if(idx == 0)return (arr[idx] == sum);
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        bool notTaken = solve(arr, idx-1, sum , dp);
        bool taken = false;
        if(sum >= arr[idx]){
            taken = solve(arr, idx-1 , sum - arr[idx] , dp);
        }
        return dp[idx][sum] =  taken || notTaken;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1 , vector<int>(sum+1 , -1));
        
        return solve(arr , n-1 , sum, dp);
    }
};