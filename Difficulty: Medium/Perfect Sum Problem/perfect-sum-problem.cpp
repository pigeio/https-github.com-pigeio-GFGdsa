class Solution {
  public:
    int n;
    long long t[1001][1001];
    int solve(vector<int>& arr,int idx , int target){
        
        if(idx == n) return target == 0 ? 1:0;
        
        if(t[idx][target] != -1){
            return t[idx][target];
        }
        
        int taken = 0;
        if(arr[idx] <= target){
            taken = solve(arr, idx+1 , target-arr[idx]);
            
        }
        int notTaken = solve(arr , idx+1 , target);
        return t[idx][target] = taken + notTaken;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        n = arr.size();
        memset(t , -1 , sizeof(t));
        return solve(arr, 0 , target);
    }
};