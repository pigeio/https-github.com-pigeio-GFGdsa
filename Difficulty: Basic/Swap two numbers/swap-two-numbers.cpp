// User function Template for C++

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // complete the function here
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;
        
        return {a,b};
    }
};