class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        int n = arr.size();
        int m = dep.size();
        
        int pF = 1, max_pF = 1;
        int i = 1 ,j= 0;
        
        while(i < n && j < n){
            if(dep[j] >= arr[i]){
                pF++;
                i++;
            }else{
                pF--;
                j++;
            }
            max_pF = max(max_pF , pF);
        }
        return max_pF;
    }
};
