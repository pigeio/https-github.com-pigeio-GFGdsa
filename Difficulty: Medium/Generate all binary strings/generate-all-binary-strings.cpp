// User function Template for C++

class Solution {
  public:
    void generate(int n ,string curr , vector<string>&result , char lastnumber){
        //base case
        if(n == 0){
            result.push_back(curr);
            return;
        }
        
        generate(n-1 , curr+'0' , result ,'0');
        
        if(lastnumber != '1'){
           generate(n-1 , curr+'1' , result ,'1');
        }
        
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string>result;
       
        generate(num ,"",result,'0');
        return result;
    }
};