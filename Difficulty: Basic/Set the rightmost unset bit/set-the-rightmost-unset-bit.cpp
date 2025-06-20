class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        if (n == 0) return 0;
        return (n | n+1);
    }
};