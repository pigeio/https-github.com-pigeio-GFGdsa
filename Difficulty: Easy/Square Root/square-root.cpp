//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int ans = 1;
        int low = 1 , high = n;
        while(low <=high){
            int mid = low + (high-low)/2;
            int sqrt = mid*mid;
            if(sqrt > n){
                high = mid-1;
            }else{
                ans = mid;
                low = mid+1;
            }
        }return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends