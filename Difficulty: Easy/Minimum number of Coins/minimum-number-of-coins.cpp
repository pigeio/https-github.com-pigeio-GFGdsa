// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int>ans;
        int currency[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = 10;
        
        for(int i = n-1; i >=0 ; i--){
            while(N >= currency[i]){
                N -= currency[i];
            ans.push_back(currency[i]);
            }
        }
        for(int i = 0; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
    }
};