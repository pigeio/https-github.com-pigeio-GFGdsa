class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        int temp = (1 << k);
        for(int i=0;i<n;i++){
            if((n & temp) == 0){
                return false;                
            }else{
                return true;
            }
        }
    }
};