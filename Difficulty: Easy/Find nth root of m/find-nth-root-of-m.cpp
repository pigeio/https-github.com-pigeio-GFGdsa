//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int mid , int n , int m){
        long long ans = 1;
        for(int i = 0; i<n ; i++){
            ans = ans*mid;
            if(ans > m) return 2;
            
        }if(ans == m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        // Code here.
        int start = 1 , end = m;
        while(start <= end){
            int mid = start +(end-start)/2;
            int midfun = fun(mid , n , m); // that is mid to the power n;
            if(midfun == 1){
                return mid;
            }else if(midfun == 0){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends