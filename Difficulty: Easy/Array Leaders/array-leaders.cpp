

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>ans;
        int rightmost = arr[n-1];
        ans.push_back(rightmost);
        for(int i = n-2; i>= 0; i--){
            if(arr[i] >= rightmost){
                ans.push_back(arr[i]);
                rightmost = arr[i];
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};