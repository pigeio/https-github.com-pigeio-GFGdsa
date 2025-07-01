class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> original = arr; // Store original to use for comparison
        for (int i = n - 2; i >= 0; i--) {
            if (original[i + 1] < original[i]) {
                arr[i] = original[i + 1];
            } else {
                arr[i] = -1;
            }
        }
        arr[n - 1] = -1;
    }
};
