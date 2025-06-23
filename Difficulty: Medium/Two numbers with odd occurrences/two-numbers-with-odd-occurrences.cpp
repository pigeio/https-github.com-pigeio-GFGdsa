// User function Template for C++
class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        // code here
        int ans = 0;
        for (int i =0; i<N ;i++){
            ans = ans ^ Arr[i];
        }
        
        long long setBit = ans & ~(ans-1);
        
        int x = 0 , y = 0;
        for(int i =0 ; i< N; i++){
            if(Arr[i] & setBit){
                x = x ^ Arr[i];
            }else{
                y = y ^ Arr[i];
            }
        }
        if(x > y){
            return {x , y};
        }else{
            return{y , x};
        }
    }
};