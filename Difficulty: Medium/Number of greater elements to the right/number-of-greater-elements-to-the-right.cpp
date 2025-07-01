// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int>result;
        stack<int>st;
        for(int i =0; i< queries;i++){
            int q = indices[i];
            
            int count = 0;
            for(int i=n-1;i>=q;i--){
                while(!st.empty() && arr[q] >= st.top()){
                    st.pop();
                }
                if(arr[i] > arr[q]){
                    st.push(arr[i]);
                    count++;
                    
                }
            }
            result.push_back(count);
        }
        return result;
    }
};