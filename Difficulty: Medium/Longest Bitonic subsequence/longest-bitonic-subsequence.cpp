class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int maxi = 0;
        vector<int>dp1(n , 1);
        for(int i = 0; i< n ; i++){
            for(int p = 0 ; p < i; p++){
                if(nums[p] < nums[i] && 1 + dp1[p] > dp1[i]){
                    dp1[i] = 1 + dp1[p];
                }
            }
        }
        
        vector<int>dp2(n , 1);
        for(int i = n-1; i >= 0; i--){
            for(int p = n-1; p > i; p--){
                if(nums[p] < nums[i] && 1 + dp2[p] > dp2[i]){
                    dp2[i] = 1 + dp2[p];
                }
            }
        }
        
        
        for(int i = 0; i< n; i++){
            if(dp1[i] > 1 && dp2[i] > 1)
            maxi = max(maxi , dp1[i]+dp2[i]-1);
        }
        
        return maxi;
    }
};
