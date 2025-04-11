//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        
        for(int via = 0; via < n ; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n;j++){
                    if(mat[i][via] != -1 && mat[via][j] != -1){
                        int newDist = mat[i][via] + mat[via][j];
                        if((mat[i][j] == -1 || newDist < mat[i][j])){
                            mat[i][j] = newDist;
                        }
                    }
                    
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends