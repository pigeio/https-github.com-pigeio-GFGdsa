// User function Template for C++

class Solution {
  public:
    void heapify(vector<int> &arr, int N, int i){
        
        int p = i;
        int L = 2*i+1;
        int R = 2*i+2;
            
        if(L < N && arr[L] > arr[p]){
            p = L;
        }
            
        if(R < N && arr[R] > arr[p]){
            p = R;
        }
            
        if( p != i){
            swap(arr[i] , arr[p]);
            heapify(arr , N , p);
        }
        
    }
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i = (N-2)/2 ; i >=0 ;i--){
            heapify(arr , N ,i);
        }
    }
};
