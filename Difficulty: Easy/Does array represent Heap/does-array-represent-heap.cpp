
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        for(int i = 0; i<= (n-2)/2; i++){
            int L = 2*i+1;
            int R = 2*i+2;
            
            if(L < n && arr[L] > arr[i]){
                return false;
            }
            
            if(R < n && arr[R] > arr[i]){
                return false;
            }
        }
        return true;
    }
};