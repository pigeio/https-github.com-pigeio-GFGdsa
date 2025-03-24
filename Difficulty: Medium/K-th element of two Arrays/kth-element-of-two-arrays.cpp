//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        if(a.size() > b.size()){
            return kthElement(b,a,k);
        }
        
        int m = a.size();
        int n = b.size();
        
        //base case
        if(k <=0 || k > n+m){
            return -1;
        }
        int start = max(0, k - n), end = min(k, m);
        while(start <= end){
            int px = start + (end-start)/2;
            int py = k-px;
                
            int x1 = (px == 0) ? INT_MIN : a[px-1];
            int x2 = (py == 0) ? INT_MIN : b[py-1];
            int x3 = (px == m) ? INT_MAX : a[px];
            int x4 = (py == n) ? INT_MAX : b[py];
                
            if(x1 <= x4 && x2 <= x3){
                return max(x1 , x2);
            }else if(x1 > x4){
                end = px-1;
            }else{
                start = px +1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends