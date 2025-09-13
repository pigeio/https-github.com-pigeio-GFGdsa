class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 0)return -1;
        sort(arr.begin() ,arr.end());
        return arr[n-1];
    }
};
