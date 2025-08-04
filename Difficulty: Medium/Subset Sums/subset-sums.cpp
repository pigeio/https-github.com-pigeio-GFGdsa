class Solution {
  public:
    void find(vector<int>& arr, int idx, int sum, vector<int>&results){
        if(idx == arr.size()){
            results.push_back(sum);
            return;
        }
        
        
            find(arr ,idx+1,sum + arr[idx], results);
            
            find(arr ,idx+1,sum , results);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>results;
        
        
        find(arr ,0,0, results); //(arr ,idx, sum, results)
        return results;
    }
};