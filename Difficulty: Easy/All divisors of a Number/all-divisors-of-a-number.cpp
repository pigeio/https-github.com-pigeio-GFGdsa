class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int>ans;
        for (int i=1; i*i<=n; i++){
            if(n % i == 0){
                ans.push_back(i);
                if(i != n/i){ // 6 = 36/6 
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        for( auto &it : ans){
            cout << it << " ";
        }
       
    }
};